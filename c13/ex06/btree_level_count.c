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

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	btree_level_count_recursive(t_btree *root)
{
	int	left_result;
	int	right_result;

	if (root == NULL)
		return 0;
	left_result = btree_level_count_recursive(root->left);
	right_result = btree_level_count_recursive(root->right);

	return (max(left_result, right_result)) + 1;
}

int	btree_level_count(t_btree *root)
{
	return (btree_level_count_recursive(root));
}
