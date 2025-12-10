/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondra <tigondra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:56:20 by tigondra          #+#    #+#             */
/*   Updated: 2025/12/10 14:29:43 by tigondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_str(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] == 32)
	{
		if (!str[i + 1])
			return (0);
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (!(str[i] > 47 && str[i] < 58) && str[i] != 32)
			return (0);
		i++;
	}
	return (1);
}

static int	check_av(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!check_str(av[i]))
			return (0);
		i++;
	}
	return (1);
}

t_stack	*ft_fill_tab_str(char *str)
{
	int		i;
	t_stack	*stack;
	t_node	*node;

	if (!str || check_str(str) == 0)
		return (NULL);
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

t_stack	*ft_fill_tab_av(char **av)
{
	int		i;
	t_stack	*stack;
	t_node	*node;

	if (check_av(av) == 0)
		return (NULL);
	node = init_node(ft_atoi(av[0]), NULL, NULL);
	stack = init_stack(1, node, node);
	i = 1;
	while (av[i])
	{
		node->next = init_node(ft_atoi(av[i]), node, NULL);
		node = node->next;
		stack->last = node;
		stack->size++;
		i++;
	}
	return (stack);
}
