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

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
	int	result;

	if (*root == NULL)
		*root = btree_create_node(item);
	else
	{
		result = (*cmpf)(item, (*root)->item);
		if (result < 0)
		{
			btree_insert_data(&((*root)->left), item, cmpf);
		}
		else
			btree_insert_data(&((*root)->right), item, cmpf);
	}
}
