/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondra <tigondra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:45:06 by tigondra          #+#    #+#             */
/*   Updated: 2025/12/10 15:16:55 by tigondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (!a || a->size == 0 || !b)
		return ;
	node = a->last;
	a->last = node->previous;
	if (a->last)
		a->last->next = NULL;
	else
		a->head = NULL;
	a->size--;
	if (b->size == 0)
	{
		b->head = node;
		b->last = node;
		node->previous = NULL;
	}
	else
	{
		node->previous = b->last;
		b->last->next = node;
		b->last = node;
	}
	node->next = NULL;
	b->size++;
}

void	ft_push_a(t_stack *a, t_stack *b)
{
	ft_push(b, a);
	ft_printf("pa\n");
}

void	ft_push_b(t_stack *b, t_stack *a)
{
	ft_push(a, b);
	ft_printf("pb\n");
}
