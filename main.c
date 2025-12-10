/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondra <tigondra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:56:02 by tigondra          #+#    #+#             */
/*   Updated: 2025/12/10 11:22:28 by tigondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
<<<<<<< HEAD
	if (ac == 1)
	{
		int array_a[100] = {-5, 4, 3, 2, 16, 6, 9, 8, 7, 0};
		int array_b[100] = {};
		t_stack	*stack_a = malloc(sizeof(t_stack));
		t_stack *stack_b = malloc(sizeof(t_stack));

		stack_a->data = array_a;
		stack_a->nmemb = 10;
		stack_a->head = 0;
		stack_b->data = array_b;
		stack_b->nmemb = 0;
		stack_b->head = 0;

		selection_sort(stack_a, stack_b);
		print_stack(*stack_a);
		print_stack(*stack_b);
	}
	else
	{
		int *array_a = malloc(sizeof(int) * ac - 1);
		int *array_b = malloc(sizeof(int) * 100);

		int i = 1;
		while (i <= ac - 1)
		{
			array_a[i - 1] = atoi(av[i]);
			i++;
		}
		t_stack *stack_a = malloc(sizeof(t_stack));
		t_stack *stack_b = malloc(sizeof(t_stack));

		stack_a->data = array_a;
		stack_b->data = array_b;
		stack_a->nmemb = ac - 1;
		stack_b->nmemb = 0;
		stack_a->head = 0;
		stack_b->head = 0;

		selection_sort(stack_a, stack_b);
		print_stack(*stack_a);
		print_stack(*stack_b);
	}
=======
        t_stack *a;
        t_stack *b;
>>>>>>> main
	
	a = ft_fill_tab_str(av[1]);
        b = ft_fill_tab_str(av[2]);
        print_stack(a);
        ft_swap_a(a);
        print_stack(a);
        ft_push_b(b, a);
        print_stack(a);
        print_stack(b);
        ft_reverse_rotate_a(a);
        print_stack(a);
	return (ac);
}