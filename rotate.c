/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondra <tigondra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:49:04 by tigondra          #+#    #+#             */
/*   Updated: 2025/12/10 11:20:25 by tigondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    ft_rotate(t_stack *s)
{
    t_node *node;

    if (!s || !s->head || !s->head->next)
        return;
    node = s->head;
    s->head = node->next;
    s->head->previous = NULL;
    node->previous = s->last;
    node->next = NULL;
    s->last->next = node;
    s->last = node;
}

void    ft_rotate_a(t_stack *a)
{
        ft_rotate(a);
        printf("ra\n");
}

void    ft_rotate_b(t_stack *b)
{
        ft_rotate(b);
        printf("rb\n");
}

void    ft_rotate_r(t_stack *a, t_stack *b)
{
        ft_rotate(a);
        ft_rotate(b);
        printf("rr\n");
}