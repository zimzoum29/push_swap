/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondra <tigondra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:41:41 by tigondra          #+#    #+#             */
/*   Updated: 2026/01/06 13:38:58 by tigondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *a)
{
	int	tmp;

	if (a->last->previous == NULL)
		return ;
	tmp = a->head->data;
	a->head->data = a->head->next->data;
	a->head->next->data = tmp;
}

void	ft_swap_a(t_stack *a, t_bench *bench)
{
	ft_swap(a);
	ft_printf("sa\n");
	bench->sa++;
	bench->ops++;
}

void	ft_swap_b(t_stack *b, t_bench *bench)
{
	ft_swap(b);
	ft_printf("sb\n");
	bench->sb++;
	bench->ops++;
}

void	ft_swap_s(t_stack *a, t_stack *b, t_bench *bench)
{
	ft_swap(a);
	ft_swap(b);
	ft_printf("ss\n");
	bench->ss++;
	bench->ops++;
}
