#include "push_swap.h"

static	int ft_find_max_n(const t_stack *stack_a)
{
	int max;
	int n;
	int i;
	t_node *node;

	max = (stack_a->last)->data;
	node = stack_a->head;
	i = 0;
	while (node->next != NULL)
	{
		if (node->data > max)
		{
			max = node->data;
			n = i;
		}
		node = node->next;
		i++;
	}
	return (n);
}

static void ft_replace_and_push(int n, t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	i = 0;
	while (i < n + 1)
	{
		ft_rotate_a(stack_a);
		i++;
	}
	ft_push_a(stack_a, stack_b);
}

void	ft_selection_sort(t_stack *stack_a, t_stack *stack_b)
{
	int i;
	t_node *node;
	int size;
	int n_max;

	size = stack_a->size;
	node = stack_a->head;
	i = 0;
	while (i < size)
	{
		n_max = ft_find_max_n(stack_a);
		ft_replace_and_push(n_max, stack_a, stack_b);
		i++;
	}
	i = 0;
	while (i < size)
	{
		pb(stack_a, stack_b);
		i++;
	}
}