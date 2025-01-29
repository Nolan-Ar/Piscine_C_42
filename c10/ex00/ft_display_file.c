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

#define BUFFER_SIZE 1024

void	ft_puterr(char *str)
{
	while (*str)
		write(2, str++, 1);
}

int	ft_display_file(char *filename)
{
	char	buff[BUFFER_SIZE];
	int		fb;
	int		byte_read;

	fb = open(filename, O_RDONLY);
	if (fb == -1)
		ft_puterr("Cannot read file.");
	byte_read = read(fb, buff, BUFFER_SIZE);
	while (byte_read > 0)
	{
		byte_read = read(fb, buff, BUFFER_SIZE);
		write(1, buff, byte_read);
		if (byte_read <= 0)
		{
			close(fb);
			return (0);
		}
	}
	close(fb);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		ft_puterr("File name missing.");
	if (argc > 2)
		ft_puterr("Too many arguments.");
	ft_display_file(argv[1]);
}
