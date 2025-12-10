/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondra <tigondra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:56:02 by tigondra          #+#    #+#             */
/*   Updated: 2025/12/10 12:31:27 by tigondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
        t_stack *a;
        t_stack *b;
	
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