/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondra <tigondra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:45:06 by tigondra          #+#    #+#             */
/*   Updated: 2025/12/18 11:48:28 by tigondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (!a || a->size == 0 || !b)
		return ;
	node = a->head;
	a->head = node->next;
	if (a->head)
		a->head->previous = NULL;
	else
		a->last = NULL;
	a->size--;
	if (b->size == 0)
	{
		b->last = node;
		b->head = node;
		node->next = NULL;
	}
	else
	{
		node->next = b->head;
		b->head->previous = node;
		b->head = node;
	}
	node->previous = NULL;
	b->size++;
}

void	ft_push_a(t_stack *a, t_stack *b, t_bench *bench)
{
	ft_push(b, a);
	ft_printf("pa\n");
	bench->pa++;
	bench->ops++;
}

void	ft_push_b(t_stack *b, t_stack *a, t_bench *bench)
{
	ft_push(b, a);
	ft_printf("pb\n");
	bench->pb++;
	bench->ops++;
}
