/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondra <tigondra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:56:20 by tigondra          #+#    #+#             */
/*   Updated: 2025/12/18 15:49:20 by tigondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_stack_add_back(t_stack *stack, int value)
{
	t_node	*node;

	node = ft_init_node(value, stack->last, NULL);
	if (!node)
		return (0);
	if (!stack->head)
		stack->head = node;
	else
		stack->last->next = node;
	stack->last = node;
	stack->size++;
	return (1);
}

static int	ft_is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (1);
}

static int	ft_has_duplicate(t_stack *stack, int value)
{
	t_node	*node;

	node = stack->head;
	while (node)
	{
		if (node->data == value)
			return (1);
		node = node->next;
	}
	return (0);
}

static int	ft_parse_string(t_stack *stack, char *str)
{
	int	i;
	int	value;
	int	error;

	i = 0;
	while (str[i])
	{
		while (str[i] == 32)
			i++;
		if (!str[i])
			break ;
		if (!ft_is_valid_number(&str[i]))
			return (0);
		value = ft_atoi(&str[i], &error);
		if (error)
			return (0);
		if (ft_has_duplicate(stack, value) || !ft_stack_add_back(stack, value))
			return (0);
		if (str[i] == '+' || str[i] == '-')
			i++;
		while (str[i] >= '0' && str[i] <= '9')
			i++;
	}
	return (1);
}

t_stack	*ft_fill_stack(int ac, char **av)
{
	t_stack	*stack;
	int		i;

	stack = ft_init_stack(0, NULL, NULL);
	if (!stack)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		if (!ft_parse_string(stack, av[i]))
		{
			ft_free_stack(stack);
			return (NULL);
		}
		i++;
	}
	return (stack);
}
