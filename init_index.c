/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondra <tigondra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:33:14 by pdauga            #+#    #+#             */
/*   Updated: 2025/12/18 15:48:42 by tigondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_index_zero(t_stack *stack)
{
	t_node	*node;

	node = stack->head;
	while (node)
	{
		if (node)
			node->index = 0;
		node = node->next;
	}
}

void	ft_init_index(t_stack *stack)
{
	t_node	*node;
	t_node	*node2;

	ft_set_index_zero(stack);
	node = stack->head;
	while (node)
	{
		node2 = stack->head;
		while (node2)
		{
			if (node2->data < node->data)
				node->index++;
			node2 = node2->next;
		}
		node = node->next;
	}
}
