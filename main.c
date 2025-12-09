
#include "push_swap.h"



int main(int ac, char **av)
{
	if (ac == 1)
	{
		int array_a[100] = {-5, 4, 3, 2, 16, 6, 9, 8, 7, 0};
		int array_b[100] = {};
		t_stack	*stack_a = malloc(sizeof(t_stack));
		t_stack *stack_b = malloc(sizeof(t_stack));

		stack_a->data = array_a;
		stack_a->nmemb = 10;
		stack_a->size = 100;
		stack_b->data = array_b;
		stack_b->nmemb = 0;
		stack_b->size = 100;

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
		stack_a->size = ac - 1;
		stack_b->size = ac - 1;

		selection_sort(stack_a, stack_b);
	}
	
	return (0);
}

