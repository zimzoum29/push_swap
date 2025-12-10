/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondra <tigondra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:56:20 by tigondra          #+#    #+#             */
/*   Updated: 2025/12/10 11:24:55 by tigondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_fill_tab_str(char *str)
{
	int		i;
	t_stack	*stack;
	t_node	*node;

	i = 0;
	node = init_node(ft_atoi(&str[0]), NULL, NULL);
	stack = init_stack(1, node, node);
	while (str[i] == 32)
		i++;
	while ((str[i] > 47 && str[i] < 58))
		i++;
	while (str[i])
	{
		if ((str[i] > 47 && str[i] < 58) && str[i - 1] == 32)
		{
			node->next = init_node(ft_atoi(&str[i]), node, NULL);
			node = node->next;
			stack->last = node;
			stack->size++;
		}
		i++;
	}
	return (stack);
}
