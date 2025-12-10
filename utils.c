/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondra <tigondra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:34:20 by tigondra          #+#    #+#             */
/*   Updated: 2025/12/10 10:45:11 by tigondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void print_stack(t_stack *stack)
{
	t_node *node;
	int i;
	
	i = 0;
	node = stack->head;
	printf("stack : |");
	while (node->next != NULL)
	{
		printf("%d|", node->data);
		node = node->next;
	}
	printf("%d|", node->data);
	printf("\n");
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	sum;

	i = 0;
	sign = 1;
	sum = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		sum = (sum * 10) + (str[i] - 48);
		i++;
	}
	return (sum * sign);
}
