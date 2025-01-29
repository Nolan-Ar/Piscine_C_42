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

int	size_tab_argv(char *src)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (src[i])
	{
		if (true_char(src[i]) == 0)
			return (0);
		if (src[i] >= '0' && src[i] <= '9')
			n++;
		i++;
	}
	if (n % 4 != 0)
		return (0);
	return (n / 4);
}
