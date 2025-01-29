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

int	ft_is_sort(int *tab, int length, int (*f)(int int))
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 1;
	k = 1;
	if (length <= 1)
		return (1);
	while (i < lenght - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			j = 0;
		if (f(tab[i], tab[i + 1]) > 0)
			k = 0;
		i++;
	}
	return (j || k);
}
