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

void	ft_sorted_list_insert(t_list **begin_list, void	*data, int (*cmp)())
{
	t_list	*elem;
	t_list	*current;
	t_list	*prev;

	elem = ft_create_elem(data);
	if (elem == NULL)
		return ;
	if (*begin_list == NULL || (cmp)(data, *begin_list->data) <= 0)
	{
		elem->next = *begin_list;
		*begin_list = elem;
		return ;
	}
	current = *begin_list;
	prev = NULL;
	while (current != NULL && (cmp)(data, current->data) > 0)
	{
		prev = current;
		current = current->next;
	}
	prev->next = elem;
	elem->next = current;
}
