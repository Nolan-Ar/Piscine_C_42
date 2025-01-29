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

int	ft_count_if(char **tab, int lenght, int (*f)(char))
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < lenght)
	{
		if (f(tab[i]) != 0)
			count++;
		i++;
	}
	return (count);
}
