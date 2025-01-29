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

void	ft_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (root == NULL)
		return ;
	ft_apply_infix(root->left, applyf);
	(applyf)(root->item);
	ft_apply_infix(root->right, applyf);
}
