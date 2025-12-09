/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondra <tigondra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:52:47 by tigondra          #+#    #+#             */
/*   Updated: 2025/12/09 13:38:39 by tigondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    ft_reverse_rotate(t_stack a)
{
        int     i;
	int     tmp;
        
	if (a.size <= 1)
		exit(0);
        i = a.size;
        tmp = a.data[a.size - 1];
	while (i > 0)
	{
		a.data[i] = a.data[i - 1];
		--i;
	}
	a.data[a.size - 1] = tmp;
}

void    ft_reverse_rotate_a(t_stack a)
{
        ft_reverse_rotate(a);
        printf("rra\n");
}

void    ft_reverse_rotate_b(t_stack b)
{
        ft_reverse_rotate(b);
        printf("rrb\n");
}

void    ft_reverse_rotate_r(t_stack a, t_stack b)
{
        ft_reverse_rotate(a);
        ft_reverse_rotate(b);
        printf("rrr\n");
}