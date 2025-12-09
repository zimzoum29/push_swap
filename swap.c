/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondra <tigondra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:41:41 by tigondra          #+#    #+#             */
/*   Updated: 2025/12/09 20:22:32 by tigondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    ft_swap(t_stack *a)
{
        int     tmp;
        
        if (a->size <= 1)
                exit(0);
        tmp = a->data[a->size - 1];
        a->data[a->size - 1] = a->data[a->size - 2];
        a->data[a->size - 2] = tmp;
}
void    ft_swap_a(t_stack *a)
{
        ft_swap(a);
        printf("sa\n");
}

void    ft_swap_b(t_stack *b)
{
        ft_swap(b);
        printf("sb\n");
}

void    ft_swap_s(t_stack *a, t_stack *b)
{
        ft_swap(a);
        ft_swap(b);
        printf("ss\n");
}

