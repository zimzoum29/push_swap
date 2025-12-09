/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondra <tigondra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:15:20 by tigondra          #+#    #+#             */
/*   Updated: 2025/12/09 16:24:08 by tigondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int find_index(const t_stack stack_a)
{
	int min;
	int i;
	int index;

	index = 0;
	min = stack_a.data[0];
	i = 0;
	while (i < stack_a.size)
	{
		if (stack_a.data[i] < min)
		{
			min = stack_a.data[i];
			index = i;
		}
		i++;
	}
	return (index);
}
void	ft_search_and_push(t_stack stack_a, t_stack stack_b)
{
	int i;
	int min_index;
	int j;
	int k;

	i = 0;
	j = 0;
	while (i < stack_a.size + stack_b.size)
	{
		while (j < stack_a.size)
		{
			j++;
			min_index = find_index(stack_a);
			k = 0;
			while (k < min_index + 1)
			{
				ft_rotate_a(stack_a);
				k++;
			}
			ft_push_a(stack_a, stack_b);
		}
		i++;
	}
	ft_push_a(stack_a, stack_b);
}
