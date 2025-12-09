/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondra <tigondra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:49:04 by tigondra          #+#    #+#             */
/*   Updated: 2025/12/09 16:11:45 by tigondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    ft_rotate(t_stack a)
{
        int     i;
	int     tmp;
        
	if (a.size <= 1)
		exit(0);
        i = 0;
        tmp = a.data[0];
	while (i < a.size - 1)
	{
		a.data[i] = a.data[i + 1];
		i++;
	}
	a.data[a.size - 1] = tmp;
}

// void    ft_rotate(int *head, int size)
// {
//         if (*head == size)
//                 *head = 0;
//         *head += 1;
// }

void    ft_rotate_a(t_stack a)
{
        ft_rotate(a);
        printf("ra\n");
}

void    ft_rotate_b(t_stack b)
{
        ft_rotate(b);
        printf("rb\n");
}

void    ft_rotate_r(t_stack a, t_stack b)
{
        ft_rotate(a);
        ft_rotate(b);
        printf("rr\n");
}