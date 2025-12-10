/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondra <tigondra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:56:02 by tigondra          #+#    #+#             */
/*   Updated: 2025/12/10 15:16:30 by tigondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
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

int	ft_error_free(t_stack *a)
{
	free_stack(a);
	write(2, "Error\n", 6);
	return (0);
}

int	ft_error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (0);
	else if (ac == 2)
		a = ft_fill_tab_str(av[1]);
	else
		a = ft_fill_tab_av(&av[1]);
	if (a == NULL)
		return (ft_error_free(a));
	b = init_stack(0, NULL, NULL);
	if (!b)
		return (ft_error_free(a));
	print_stack(a);
	print_stack(b);
	ft_push_a(b, a);
	print_stack(a);
	print_stack(b);
	free_stack(a);
	free_stack(b);
}
