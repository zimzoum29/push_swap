/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondra <tigondra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:49:04 by tigondra          #+#    #+#             */
/*   Updated: 2025/12/18 11:50:22 by tigondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_stack *s)
{
	t_node	*node;

	if (!s || !s->head || !s->head->next)
		return ;
	node = s->head;
	s->head = node->next;
	s->head->previous = NULL;
	node->previous = s->last;
	node->next = NULL;
	s->last->next = node;
	s->last = node;
}

void	ft_rotate_a(t_stack *a, t_bench *bench)
{
	ft_rotate(a);
	ft_printf("ra\n");
	bench->ra++;
	bench->ops++;
}

void	ft_rotate_b(t_stack *b, t_bench *bench)
{
	ft_rotate(b);
	ft_printf("rb\n");
	bench->rb++;
	bench->ops++;
}

void	ft_rotate_r(t_stack *a, t_stack *b, t_bench *bench)
{
	ft_rotate(a);
	ft_rotate(b);
	ft_printf("rr\n");
	bench->rr++;
	bench->ops++;
}
