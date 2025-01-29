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

static t_queue	*create_queue_node(t_btree *node)
{
	t_queue	*n_node;

	n_node = (t_queue *)malloc(sizeof(t_queue));
	if (n_node == NULL)
		return (NULL);
	n_node->node = node;
	n_node->next = NULL;
	return (n_node);
}

static void	enqueue(t_queue **head, t_queue **tail, t_btree *node)
{
	t_queue	*n_node;

	n_node = create_queue_node(node);
	if (n_node == NULL)
		return ;
	if (*tail)
		(*tail)->next = n_node;
	*tail = n_node;
	if (*head == NULL)
		*head = n_node;
}

static t_btree	*dequeue(t_queue **head)
{
	t_queue	*tmp;
	t_btree	*node;

	if (*head == NULL)
		return (NULL);
	tmp = *head;
	node = tmp->node;
	*head = (*head)->next;
	free(tmp);
	return (node);
}

static void	process_level(t_queue **queue, void (*applyf)(void *item,
		int current_level, int is_first_elem), int level)
{
	t_btree	*node;
	t_queue	*next_queue;
	t_queue	*tail;
	int		level_size;

	next_queue = NULL;
	tail = NULL;
	level_size = 0;
	while (*queue != NULL)
	{
		node = dequeue(queue);
		if (node != NULL)
		{
			applyf(node->item, level, (level_size == 0));
			if (node->left)
				enqueue(&next_queue, &tail, node->left);
			if (node->right)
				enqueue(&next_queue, &tail, node->right);
			level_size++;
		}
	}
	*queue = next_queue;
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
	int current_level, int is_first_elem))
{
	t_queue	*queue;
	t_queue	*tail;
	int		level;

	if (root == NULL || applyf == NULL)
		return ;
	queue = NULL;
	tail = NULL;
	enqueue(&queue, &tail, root);
	level = 0;
	while (queue != NULL)
	{
		process_level(&queue, applyf, level);
		level++;
	}
}
