/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondra <tigondra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:41:41 by tigondra          #+#    #+#             */
/*   Updated: 2025/12/15 13:10:33 by tigondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_stack *a)
{
	int	tmp;

	if (a->last->previous == NULL)
		return ;
	tmp = a->head->data;
	a->head->data = a->head->next->data;
	a->head->next->data = tmp;
}

void	ft_swap_a(t_stack *a)
{
	ft_swap(a);
	ft_printf("sa\n");
}

void	ft_swap_b(t_stack *b)
{
	ft_swap(b);
	ft_printf("sb\n");
}

void	ft_swap_s(t_stack *a, t_stack *b)
{
	ft_swap(a);
	ft_swap(b);
	ft_printf("ss\n");
}
