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

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*first;
	t_list	*current;
	void	*tmp;

	first = *begin_list;
	if (begin_list == NULL || *begin_list == NULL)
		return ;
	while (first != NULL)
	{
		current = first->next;
		while (current != NULL)
		{
			if ((cmp)(first->data, current->data) > 0)
			{
				tmp = first->data;
				first->data = current->data;
				current->data = tmp;
			}
			current = current->next;
		}
		first = first->next;
	}
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
	int (*cmp)())
{
	t_list	*current;

	if (begin_list1 == NULL)
		return ;
	if(*begin_list1 == NULL)
		*begin_list1 = begin_list2;
	else
	{
		current = *begin_list1;
		while (current->next != NULL)
			current = current->next;
		current->next = begin_list2;
	}
	ft_list_sort(begin_list1, cmp);
}
