/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondra <tigondra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:45:06 by tigondra          #+#    #+#             */
/*   Updated: 2025/12/10 11:28:20 by tigondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_push(t_stack *a, t_stack *b)
{
    t_node *node;

    if (!a || a->size == 0)
        return;
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
        node->next = NULL;
    }
    else
    {
        node->previous = b->last;
        node->next = NULL;
        b->last->next = node;
        b->last = node;
    }
    b->size++;
}



void    ft_push_a(t_stack *a, t_stack *b)
{
        ft_push(a, b);
        printf("pa\n");
}

void    ft_push_b(t_stack *b, t_stack *a)
{
        ft_push(b, a);
        printf("pb\n");
}