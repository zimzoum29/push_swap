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
	printf("%d, %d",min, index);
	return (index);
}
void search_and_push(t_stack *stack_a, t_stack *stack_b)
{
	int i;
	int n;
	int min_index;
	int j;
	int k;
	int n1;

	i = 0;
	k = 0;
	n1 = stack_a->nmemb + stack_b->nmemb;

	while (k < n1)
	{
		n = stack_a->nmemb;
		while (i < n)
		{
			i++;
			min_index = find_index(stack_a);
			j = 0;
			while (j < min_index + 1)
			{
				ra(stack_a);
				j++;
			}
			pa(stack_a, stack_b);
		}
		k++;
	}
	test
	pa(stack_a, stack_b);
}

void	selection_sort(t_stack *stack_a, t_stack *stack_b)
{
	int i;
	int n;

	i = 0;
	n = stack_a->nmemb;
	search_and_push(stack_a, stack_b);
	printf("stack a : ");
	print_stack(*stack_a);
	printf("stack b : ");
	print_stack(*stack_b);
}