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
