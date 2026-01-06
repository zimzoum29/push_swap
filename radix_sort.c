/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondra <tigondra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:07:33 by tigondra          #+#    #+#             */
/*   Updated: 2026/01/06 13:01:45 by tigondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get(int value, int bit_pos)
{
	return ((value >> bit_pos) & 1);
}

int	ft_get_max_bits(t_stack *stack)
{
	t_node	*current;
	unsigned int		max_index;
	int		max_bits;

	if (stack->size == 0)
		return (0);
	current = stack->last;
	max_index = current->index;
	while (current->previous != NULL)
	{
		current = current->previous;
		if (current->index > max_index)
			max_index = current->index;
	}
	max_bits = 0;
	while ((max_index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	ft_search_and_push(t_stack *stack_a, t_stack *stack_b, int bit_pos,
		t_bench *bench)
{
	if (ft_get(stack_a->head->index, bit_pos) == 0)
	{
		ft_push_b(stack_a, stack_b, bench);
	}
	else
		ft_rotate_a(stack_a, bench);
}

void	ft_radix_sort(t_stack *stack_a, t_stack *stack_b, t_bench *bench)
{
	t_node	*node;
	int		i;
	int		bit_pos;
	int		max_bits;

	bench->comp = 3;
	bench->strat = 3;
	ft_init_index(stack_a);
	i = 0;
	bit_pos = 0;
	max_bits = ft_get_max_bits(stack_a);
	while (bit_pos < max_bits)
	{
		while (stack_a->size > 0 && ft_get(stack_a->head->index, bit_pos) == 0)
			ft_push_b(stack_a, stack_b, bench);
		node = stack_a->head;
		ft_rotate_a(stack_a, bench);
		while (stack_a->size > 0 && node->index != stack_a->head->index)
		{
			ft_search_and_push(stack_a, stack_b, bit_pos, bench);
		}
		while (stack_b->size > 0)
			ft_push_a(stack_a, stack_b, bench);
		bit_pos++;
	}
}
