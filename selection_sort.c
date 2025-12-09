/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondra <tigondra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:15:20 by tigondra          #+#    #+#             */
/*   Updated: 2025/12/09 20:28:25 by tigondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stack *a, t_stack *b)
{
	int i;
	int j;
	int size;

	i = 0;
	j = 0;
	size = a->size;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_rotate_a(a);
			print_stack(*a);
			if (a->data[a->size - 1] < a->data[a->size - 2])
			{
				ft_swap_a(a);
				print_stack(*a);
			}
			j++;
		}
		ft_push_a(a,b);
		i++;
	}
}
