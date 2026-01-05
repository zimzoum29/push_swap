/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondra <tigondra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 09:46:09 by tigondra          #+#    #+#             */
/*   Updated: 2026/01/05 13:17:28 by tigondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_init_stack(int size, t_node *head, t_node *last)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = size;
	stack->head = head;
	stack->last = last;
	return (stack);
}

t_node	*ft_init_node(int data, t_node *previous, t_node *next)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->data = data;
	node->previous = previous;
	node->next = next;
	return (node);
}

void	ft_free_node(t_node *node)
{
	if (!node)
		return ;
	free(node);
}

void	ft_free_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*next;

	if (!stack)
		return ;
	node = stack->head;
	while (node)
	{
		next = node->next;
		free(node);
		node = next;
	}
	free(stack);
}

int	ft_free_stacks(t_stack *a, t_stack *b)
{
	if (a)
		ft_free_stack(a);
	if (b)
		ft_free_stack(b);
	return (0);
}
