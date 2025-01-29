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

t_list	*ft_free_list(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*next;

	if (begin_list == NULL)
		return (NULL);
	next = begin_list->next;
	(free_fct)(begin_list->data);
	free(begin_list);
	return (next);
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
	void (*free_fct)(void *))
{
	t_list	*current;

	while (*begin_list != NULL && (cmp)((*begin_list)->data, data_ref) == 0)
		*begin_list = ft_free_list(*begin_list, free_fct);
	current = *begin_list;
	while (current != NULL && current->next != NULL)
	{
		if ((cmp)(current->next->data, data_ref) == 0)
			current->next = ft_free_list(current->next, free_fct);
		else
			current = current->next;
	}
}
