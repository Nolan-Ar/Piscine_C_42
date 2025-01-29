/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourusername <yourusername@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:00:00 by yourusername     #+#    #+#              */
/*   Updated: 2024/05/27 10:00:00 by yourusername    ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>

#define BUFF_SIZE 29824

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_puterr(char *file_name, char *str)
{
	write(2, file_name, ft_strlen(file_name));
	write(2, ": ", 2);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
}

int	ft_display_file(char *file_name, char *argv)
{
	char	buff[BUFF_SIZE];
	int		fb;
	int		byte_read;

	fb = open(argv, O_RDONLY);
	if (fb == -1)
	{
		ft_puterr(file_name, strerror(errno));
		return (1);
	}
	byte_read = read(fb, buff, BUFF_SIZE);
	while (byte_read > 0)
	{
		write(1, buff, byte_read);
		byte_read = read(fb, buff, BUFF_SIZE);
	}
	if (byte_read < 0)
	{
		ft_puterr(file_name, strerror(errno));
		close(fb);
		return (1);
	}
	close(fb);
	return (0);
}

int	ft_cat(int argc, char **argv)
{
	int	i;
	char	*file_name;

	i = 1;
	file_name = basename(argv[0]);
	if (argc < 2)
	{
		ft_puterr(file_name, "File name missing.");
		return (1);
	}
	while (i < argc)
	{
		if (ft_display_file(file_name, argv[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	return (ft_cat(argc, argv));
}
