/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondra <tigondra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:33:14 by pdauga            #+#    #+#             */
/*   Updated: 2025/12/16 15:26:50 by tigondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_index(t_stack *stack)
{
	int		count;
	t_node	*node;
	t_node	*node2;

	node = stack->head;
	while (node)
	{
		count = 0;
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
