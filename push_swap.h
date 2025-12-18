/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondra <tigondra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:24:27 by tigondra          #+#    #+#             */
/*   Updated: 2025/12/18 15:47:52 by tigondra         ###   ########.fr       */
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
}	t_node;

typedef struct s_stack
{
	int				size;
	struct s_node	*head;
	struct s_node	*last;
}	t_stack;

typedef struct s_bench
{
	int	enable;
	int	ops;
	int	disorder;
	int	strat;
	int	comp;
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_bench;

t_stack	*ft_init_stack(int size, t_node *head, t_node *last);
t_node	*ft_init_node(int data, t_node *previous, t_node *next);
void	ft_free_node(t_node *node);
void	ft_free_stack(t_stack *stack);
int		ft_free_stacks(t_stack *a, t_stack *b);

void	ft_init_index(t_stack *stack);

t_stack	*ft_fill_stack(int ac, char **av);

void	ft_swap_a(t_stack *a, t_bench *bench);
void	ft_swap_b(t_stack *b, t_bench *bench);
void	ft_swap_s(t_stack *a, t_stack *b, t_bench *bench);

void	ft_push_a(t_stack *a, t_stack *b, t_bench *bench);
void	ft_push_b(t_stack *a, t_stack *b, t_bench *bench);

void	ft_rotate_a(t_stack *a, t_bench *bench);
void	ft_rotate_b(t_stack *b, t_bench *bench);
void	ft_rotate_r(t_stack *a, t_stack *b, t_bench *bench);

void	ft_reverse_rotate_a(t_stack *a, t_bench *bench);
void	ft_reverse_rotate_b(t_stack *b, t_bench *bench);
void	ft_reverse_rotate_r(t_stack *a, t_stack *b, t_bench *bench);

void	ft_selection_sort(t_stack *stack_a, t_stack *stack_b, t_bench *bench);
void	ft_radix_sort(t_stack *stack_a, t_stack *stack_b, t_bench *bench);
void	ft_adaptive_sort(t_stack *a, t_stack *b, t_bench *bench);

int		ft_atoi(char *str, int *error);
int		ft_strcmp(char *s1, char *s2);

void	ft_init_bench(t_bench *bench);
void	ft_create_benchmark(t_bench *bench);

#endif