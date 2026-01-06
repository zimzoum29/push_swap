/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondra <tigondra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:29:09 by tigondra          #+#    #+#             */
/*   Updated: 2026/01/05 15:57:01 by tigondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    push_current_bucket(t_stack *a, t_stack *b, int current_bucket, t_bench *bench)
{
    int    n_pushed;
    int    sq;
    int    reste;

    sq = ft_sqrt(a->size + b->size);
    n_pushed = 0;
    while (n_pushed != sq)
    {
        if (a->head->index >= (current_bucket * sq)
            && a->head->index < (current_bucket + 1) * sq)
        {
            ft_push_b(a, b, bench);
            n_pushed++;
        }
        else
            ft_rotate_a(a, bench);
    }
    current_bucket++;
    if (current_bucket == sq)
    {
        reste = a->size;
        while (a->size > 0)
            ft_push_b(a, b, bench);
        return (reste);
    }
    return (-2); // on est pas encore a la fin
}

int    find_max_first_n(t_stack *stack, int n)
{
    t_node    *node;
    int        i;
    int        max;
    int        pos;

    node = stack->head;
    if (!node)
        return (-1);
    max = node->index;
    pos = 0;
    i = 0;
    while (node && i < n)
    {
        if (node->index > max)
        {
            max = node->index;
            pos = i;
        }
        node = node->next;
        i++;
    }
    return (pos);
}

void    push_n(t_stack *stack_a, t_stack *stack_b, t_bench *bench, int n)
{
    int    i;

    i = 0;
    while (i < n)
    {
        ft_rotate_b(stack_b, bench);
        i++;
    }
    ft_push_a(stack_a, stack_b, bench);
    while (i > 0)
    {
        ft_reverse_rotate_b(stack_b, bench);
        i--;
    }
}

int    ft_bucket_sort(t_stack *stack_a, t_stack *stack_b, t_bench *bench)
{
    int    current_bucket;
    int    sq;
    int    reste;
    int    jsp;

	bench->comp = 2;
    ft_init_index(stack_a);
    sq = ft_sqrt(stack_a->size);
    current_bucket = 0;
    while (current_bucket != sq)
    {
        reste = push_current_bucket(stack_a, stack_b, current_bucket, bench);
        current_bucket++;
    }
    while (current_bucket >= 0)
    {
        jsp = 0;
        while (jsp < sq)
        {
            push_n(stack_a, stack_b, bench, find_max_first_n(stack_b, sq));
            jsp++;
        }
        current_bucket--;
    }
    return (0);
}
