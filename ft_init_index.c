/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdauga <pdauga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:33:14 by pdauga            #+#    #+#             */
/*   Updated: 2025/12/15 14:32:56 by pdauga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void init_index(t_stack *stack)
{
	t_node *node;
	t_node *node2;
	int count;
	
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