/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondra <tigondra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:56:02 by tigondra          #+#    #+#             */
/*   Updated: 2025/12/09 20:24:31 by tigondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
        t_stack a;
        t_stack b;
        if (ac == 2)
                a = ft_fill_tab_str(av[1]);
        else if (ac > 2)
                a = ft_fill_tab_int(&av[1], ac - 1);
        b.data = malloc(sizeof(int) * a.size);
        b.size = 0;
        print_stack(b);
        //ft_push_a(&a, &b);
        ft_sort(&a, &b);
        print_stack(a);
        print_stack(b);
        free(a.data);
        free(b.data);
	return (ac);
}