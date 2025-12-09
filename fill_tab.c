/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondra <tigondra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:56:20 by tigondra          #+#    #+#             */
/*   Updated: 2025/12/09 15:54:17 by tigondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_size_tab(char *str)
{
	int	i;
	int	count;

	count = 0;
	if (str[0] > 47 && str[0] < 58)
		count++;
	if (str[0] != 32 && count == 0)
		return (-1);
	i = 1;
	while (str[i])
	{
		if ((str[i] > 47 && str[i] < 58) && str[i - 1] == 32)
			count++;
		if (!(str[i] > 47 && str[i] < 58) && str[i] != 32)
			return (-1);
		i++;
	}
	return (count);
}

t_stack	null_tab(void)
{
	t_stack	stack;

	stack.size = 0;
	stack.data = NULL;
	return (stack);
}

t_stack	ft_fill_tab_str(char *str)
{
	int		i;
	int		index;
	t_stack	stack;

	index = 0;
	stack.size = ft_size_tab(str);
	if (stack.size == -1)
		return (null_tab());
	stack.data = malloc(sizeof(int) * stack.size);
	if (!stack.data)
		return (null_tab());
	if (str[0] > 47 && str[0] < 58)
	{
		stack.data[0] = ft_atoi(&str[i]);
		index++;
	}
	i = 1;
	while (str[i])
	{
		if ((str[i] > 47 && str[i] < 58) && str[i - 1] == 32)
			stack.data[index++] = ft_atoi(&str[i]);
		i++;
	}
	return (stack);
}

t_stack	ft_fill_tab_int(char **tab, int size)
{
	t_stack	stack;
	int i;
	
	stack.size = size;
	i = 0;
	stack.data = malloc(sizeof(int) * size);
	while (tab[i])
	{
		stack.data[i] = ft_atoi(tab[i]);
		i++;
	}
	return (stack);
}
