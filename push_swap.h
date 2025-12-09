/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondra <tigondra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:24:27 by tigondra          #+#    #+#             */
/*   Updated: 2025/12/09 16:19:22 by tigondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*data;
	int	size;
}		t_stack;

void	ft_swap_a(t_stack a);
void	ft_swap_b(t_stack b);
void	ft_swap_s(t_stack a, t_stack b);

void	ft_push_a(t_stack a, t_stack b);
void	ft_push_b(t_stack a, t_stack b);

void	ft_rotate_a(t_stack a);
void	ft_rotate_b(t_stack b);
void	ft_rotate_r(t_stack a, t_stack b);

void	ft_reverse_rotate_a(t_stack a);
void	ft_reverse_rotate_b(t_stack b);
void	ft_reverse_rotate_r(t_stack a, t_stack b);

void	ft_search_and_push(t_stack stack_a, t_stack stack_b);

void	print_stack(t_stack stack);

int		ft_atoi(const char *str);
t_stack	ft_fill_tab_str(char *str);
t_stack	ft_fill_tab_int(char **tab, int size);

#endif