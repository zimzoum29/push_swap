/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondra <tigondra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:45:06 by tigondra          #+#    #+#             */
/*   Updated: 2025/12/09 20:23:40 by tigondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    ft_push(t_stack *a, t_stack *b)
{
        if (a->size == 0)
                exit(0);
        b->data[b->size] = a->data[a->size - 1];
        b->size++;
        a->size--;
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