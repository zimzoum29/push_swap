/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondra <tigondra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:24:27 by tigondra          #+#    #+#             */
/*   Updated: 2025/12/16 14:38:05 by tigondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*previous;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	int				size;
	struct s_node	*head;
	struct s_node	*last;
}					t_stack;

t_stack				*init_stack(int size, t_node *head, t_node *last);
t_node				*init_node(int data, t_node *previous, t_node *next);
void				free_node(t_node *node);

void				ft_swap_a(t_stack *a);
void				ft_swap_b(t_stack *b);
void				ft_swap_s(t_stack *a, t_stack *b);

void				ft_push_a(t_stack *a, t_stack *b);
void				ft_push_b(t_stack *a, t_stack *b);

void				ft_rotate_a(t_stack *a);
void				ft_rotate_b(t_stack *b);
void				ft_rotate_r(t_stack *a, t_stack *b);

void				ft_reverse_rotate_a(t_stack *a);
void				ft_reverse_rotate_b(t_stack *b);
void				ft_reverse_rotate_r(t_stack *a, t_stack *b);

void				ft_selection_sort(t_stack *stack_a, t_stack *stack_b);

void				ft_radix_sort(t_stack *stack_a, t_stack *stack_b);

void				print_stack(t_stack *stack);

void				init_index(t_stack *stack);

int					ft_atoi_safe(char *str, int *error);
t_stack				*ft_fill_stack(int ac, char **av);

void				free_stack(t_stack *stack);

#endif