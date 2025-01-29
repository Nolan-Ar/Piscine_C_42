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

void	cpy_board_data(int **board, int *data, int size, int row)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < size - 1)
	{
		board[row][i] = data[j];
		i++;
		j++;
	}
}
