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

int	*seed_tab(char *src)
{
	int	i;
	int	j;
	int	count;
	int	*t_seed;

	count = size_tab_argv(src) * 4;
	t_seed = malloc(count * sizeof(int));
	if (t_seed == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < count)
	{
		if (src[j] >= 48 && src[j] <= 57)
		{
			t_seed[i] = src[j] % 8;
			i++;
		}
		j++;
	}
	return (t_seed);
}
