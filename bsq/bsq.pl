#!/usr/bin/env perl
use strict; use warnings;

sub read_all {
    my ($fh) = @_;
    local $/ = undef;
    my $data = <$fh> // '';
    return $data;
}

sub parse_header {
    my ($buf) = @_;
    my $pos = index($buf, "\n");
    return () if $pos < 4;
    my $head = substr($buf, 0, $pos);
    my ($rows_str, $empty, $obst, $full) = ($head =~ /^(\d+)(.)(.)(.)$/) or return ();
    my $rows = int($rows_str);
    return () if $rows <= 0;
    return ($rows, $empty, $obst, $full, $pos + 1);
}

sub parse_map {
    my ($buf, $off, $rows, $empty, $obst) = @_;
    my @grid = ();
    my $cols = undef;
    my $i = $off;
    for my $r (0..$rows-1) {
        my $nl = index($buf, "\n", $i);
        return () if $nl < 0;
        my $line = substr($buf, $i, $nl - $i);
        return () if length($line) == 0;
        $cols //= length($line);
        return () if length($line) != $cols;
        return () if $line =~ /[^\Q$empty\E\Q$obst\E]/;
        push @grid, [ split(//, $line) ];
        $i = $nl + 1;
    }
    return (\@grid, $cols);
}

sub solve_bsq {
    my ($grid, $rows, $cols, $obst) = @_;
    my @dp = (0) x ($cols + 1);
    my ($max, $mr, $mc) = (0, 0, 0);
    for my $r (0..$rows-1) {
        my $prev_diag = 0;
        for my $c (1..$cols) {
            my $tmp = $dp[$c];
            if ($grid->[$r][$c-1] eq $obst) {
                $dp[$c] = 0;
            } else {
                my $a = $dp[$c];      # top
                my $b = $dp[$c-1];    # left
                my $d = $prev_diag;   # top-left
                my $m = $a < $b ? $a : $b; $m = $d if $d < $m;
                $dp[$c] = $m + 1;
                if ($dp[$c] > $max) { $max = $dp[$c]; $mr = $r; $mc = $c-1; }
            }
            $prev_diag = $tmp;
        }
    }
    return ($max, $mr, $mc);
}

sub fill_square {
    my ($grid, $size, $mr, $mc, $full) = @_;
    return if $size <= 0;
    for my $r ($mr-$size+1 .. $mr) {
        for my $c ($mc-$size+1 .. $mc) {
            $grid->[$r][$c] = $full;
        }
    }
}

sub print_grid {
    my ($grid) = @_;
    for my $r (@$grid) {
        print join('', @$r), "\n";
    }
}

sub process {
    my ($content) = @_;
    my ($rows, $empty, $obst, $full, $off) = parse_header($content);
    unless (defined $rows) { print STDERR "map error\n"; return; }
    my ($grid, $cols) = parse_map($content, $off, $rows, $empty, $obst);
    unless ($grid) { print STDERR "map error\n"; return; }
    my ($size, $mr, $mc) = solve_bsq($grid, $rows, $cols, $obst);
    fill_square($grid, $size, $mr, $mc, $full);
    print_grid($grid);
}

if (@ARGV) {
    for my $file (@ARGV) {
        my $fh;
        if (!open($fh, '<', $file)) { print STDERR "map error\n"; next; }
        my $data = read_all($fh);
        close $fh;
        process($data);
        print "\n" if $file ne $ARGV[-1];
    }
} else {
    my $data = read_all(*STDIN);
    process($data);
}
