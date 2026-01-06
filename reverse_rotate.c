/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondra <tigondra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:52:47 by tigondra          #+#    #+#             */
/*   Updated: 2026/01/06 14:14:24 by tigondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_stack *s)
{
	t_node	*node;

	if (!s || !s->head || !s->head->next)
		return ;
	node = s->last;
	s->last = node->previous;
	s->last->next = NULL;
	node->next = s->head;
	node->previous = NULL;
	s->head->previous = node;
	s->head = node;
}

void	ft_reverse_rotate_a(t_stack *a, t_bench *bench)
{
	ft_reverse_rotate(a);
	ft_printf("rra\n");
	bench->rra++;
	bench->ops++;
}

void	ft_reverse_rotate_b(t_stack *b, t_bench *bench)
{
	ft_reverse_rotate(b);
	ft_printf("rrb\n");
	bench->rrb++;
	bench->ops++;
}

void	ft_reverse_rotate_r(t_stack *a, t_stack *b, t_bench *bench)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	ft_printf("rrr\n");
	bench->rrr++;
	bench->ops++;
}
