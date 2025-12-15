/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondra <tigondra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 11:43:54 by tigondra          #+#    #+#             */
/*   Updated: 2025/12/15 14:36:28 by tigondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_find_min_n(const t_stack *stack_a)
{
	int		min;
	int		n;
	int		i;
	t_node	*node;

	min = (stack_a->head)->data;
	node = stack_a->head;
	i = 0;
	n = 0;
	while (node != NULL)
	{
		if (node->data < min)
		{
			min = node->data;
			n = i;
		}
		node = node->next;
		i++;
	}
	return (n);
}

static void	ft_replace_and_push(int n, t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	if (n <= a->size / 2)
	{
		while (i < n)
		{
			ft_rotate_a(a);
			i++;
		}
	}
	else
	{
		while (i < a->size - n)
		{
			ft_reverse_rotate_a(a);
			i++;
		}
	}
	ft_push_b(a, b);
}

void	ft_selection_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;
	int		i;
	int		size;
	int		n_min;

	size = stack_a->size;
	node = stack_a->head;
	i = 0;
	while (i < size)
	{
		n_min = ft_find_min_n(stack_a);
		ft_replace_and_push(n_min, stack_a, stack_b);
		i++;
	}
	i = 0;
	while (i < size)
	{
		ft_push_a(stack_a, stack_b);
		i++;
	}
}
