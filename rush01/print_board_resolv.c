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
#include "libft.h"

void	print_board_resolv(int **board, int size)
{
	int	i;
	int	j;

	i = 1;
	while (i < size - 1)
	{
		j = 1;
		while (j < size - 1)
		{
			ft_putchar('0' + board[i][j]);
			if (j < size - 1)
				ft_putchar(' ');
			j++;
		}
		if (i < size - 1)
			ft_putchar('\n');
		i++;
	}
}
