#include "push_swap.h"

static int find_index(const t_stack *stack_a)
{
	int min;
	int i;
	int index;

	index = 0;
	min = stack_a->data[0];
	i = 0;
	while (i < stack_a->nmemb)
	{
		if (stack_a->data[i] < min)
		{
			min = stack_a->data[i];
			index = i;
		}
		i++;
	}
	return (index);
}
void search_and_push(t_stack *stack_a, t_stack *stack_b)
{
	int i;
	int n;
	int min_index;
	int j;

	while (i < n)
	{
		i++;
		min_index = find_index(stack_a);
		j = 0;
		if (min_index <= stack_a->nmemb / 2)
		{
			while (j < min_index + 1)
			{
				ra(stack_a);
				j++;
			}
		}
		else
		{
			while (j < stack_a->nmemb - min_index - 1)
			{
				rra(stack_a);
				j++;
			}
		}
	}
	pa(stack_a, stack_b);
}

void	selection_sort(t_stack *stack_a, t_stack *stack_b)
{
	int i;
	int n;

	i = 0;
	n = stack_a->nmemb;
	while (i <= n)
	{
		i++;
		search_and_push(stack_a, stack_b);
		print_stack(*stack_b);
	}
}

void ra2(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
}