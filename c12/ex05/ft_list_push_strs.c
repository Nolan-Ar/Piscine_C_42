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

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*head;
	t_list	*elem;
	int		i;

	if (size <= 0)
		return (NULL);
	head = NULL;
	i = 1;
	while (i < size)
	{
		elem = ft_create_elem(strs[i]);
		if (elem  == NULL)
			return (NULL);
		elem->next = head;
		head = elem;
		i++;
	}
	elem = ft_create_elem(strs[0]);
	if (elem == NULL)
		return (NULL);
	elem->next = head;
	head = elem;
	return (head);
}
