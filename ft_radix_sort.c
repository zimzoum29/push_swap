/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondra <tigondra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:07:33 by tigondra          #+#    #+#             */
/*   Updated: 2025/12/17 16:57:01 by tigondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_bit(int value, int bit_pos)
{
	return ((value >> bit_pos) & 1);
}

int	get_max_bits(t_stack *stack)
{
	t_node	*current;
	int		max_index;
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

void	ft_search_and_push(t_stack *stack_a, t_stack *stack_b, int bit_pos)
{
	if (get_bit(stack_a->head->index, bit_pos) == 0)
	{
		ft_push_b(stack_a, stack_b);
	}
	else
		ft_rotate_a(stack_a);
}

void	ft_radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;
	int		i;
	int		bit_pos;
	int		max_bits;

	init_index(stack_a);
	i = 0;
	bit_pos = 0;
	max_bits = get_max_bits(stack_a);
	while (bit_pos < max_bits)
	{
		while (stack_a->size > 0 && get_bit(stack_a->head->index, bit_pos) == 0)
			ft_push_b(stack_a, stack_b);
		node = stack_a->head;
		ft_rotate_a(stack_a);
		while (stack_a->size > 0 && node->index != stack_a->head->index)
		{
			ft_search_and_push(stack_a, stack_b, bit_pos);
		}
		while (stack_b->size > 0)
			ft_push_a(stack_a, stack_b);
		bit_pos++;
	}
}
