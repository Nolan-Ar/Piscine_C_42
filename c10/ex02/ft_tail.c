#include "ft_tail.h"



void	print_names(int i, int argc, char **argv)
{
	if (argc > 4)
	{
		if (i > 3)
			write(1, "\n==> ", 5);
		else
			write(1, "==> ", 4);
		write(1, argv[i], strlen(argv[i]));
		write(1, " <==\n", 5);
	}
}

int		size_files(int i, char **argv)
{
	int		fd2;
	char	buffer;
	int		size = 0;

	fd2 = open(argv[i], O_RDONLY);
	if (fd2 < 0)
		return (-1);
	while (read(fd2, &buffer, 1))
		size++;
	close(fd2);
	return (size);
}

void	disp_files(int i, int fd, int argc, char **argv)
{
	char	buffer;
	int		offset;
	int		readed = 0;
	int		size_file;

	size_file = size_files(i, argv);
	if (size_file == -1)
	{
		write(2, "ft_tail: ", 9);
		write(2, argv[i], strlen(argv[i]));
		write(2, ": No such file or directory\n", 28);
		return;
	}
	offset = ft_atoi(argv[2]);
	print_names(i, argc, argv);

	// Se déplacer dans le fichier pour lire les derniers octets
	while (readed < (size_file - offset))
		readed += read(fd, &buffer, 1);
	while (read(fd, &buffer, 1))
		write(1, &buffer, 1);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		i;

	if (argc < 4)
	{
		write(2, "Usage: ./ft_tail -c <bytes> <file1> <file2> ...\n", 48);
		return (1);
	}
	for (i = 3; i < argc; i++)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd >= 0)
		{
			disp_files(i, fd, argc, argv);
			close(fd);
		}
		else
		{
			write(2, "ft_tail: ", 9);
			write(2, argv[i], strlen(argv[i]));
			write(2, ": No such file or directory\n", 28);
		}
	}
	return (0);
}

