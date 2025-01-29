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

int	**tab_facto(int n)
{
	int	**tab;
	int	i;
	int	j;
	int	k;
	int	l;

	i = 0;
	k = 2;
	l = 1;
	j = ft_recursive_factorial(n) / n;
	tab = (int **)malloc(ft_recursive_factorial(n) * sizeof(int *));
	while (i < ft_recursive_factorial(n))
	{
		if (k == n - 1)
			k = 1;
		tab[i] = (int *)malloc(n * sizeof(int));
		if (i == 0)
			creat_base_tab(tab[i], n);
		if (i > 0)
		{
			tab_cpy(tab[i], tab[i - 1], n);
			chang_tab(tab[i], k);
		}
		if (i == j)
		{
			chang_base_tab(tab[i], l);
			j += ft_recursive_factorial(n) / n;
			l++;
		}
		k++;
		i++;
	}
	return (tab);
}
