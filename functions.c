#include "push_swap.h"
#define test printf("test");

void sa(t_stack *stack_a)
{
	int i = 0;
	int temp;

	if (stack_a->nmemb <= 1 || stack_a->size <= 1)
		return ;
	temp = stack_a->data[stack_a->size - 1];
	stack_a->data[stack_a->size - 1] = stack_a->data[stack_a->size - 2];
	stack_a->data[stack_a->size - 2] = temp;
}

void sb(t_stack *stack_b)
{
	int i = 0;
	int temp;

	if (stack_b->nmemb <= 1 || stack_b->size <= 1)
		return ;
	temp = stack_b->data[stack_b->size - 1];
	stack_b->data[stack_b->size - 1] = stack_b->data[stack_b->size - 2];
	stack_b->data[stack_b->size - 2] = temp;
}

void ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void pa(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->nmemb <= 1 || stack_b->size == stack_b->nmemb)
		return ;
	stack_b->data[stack_b->nmemb] = stack_a->data[stack_a->nmemb - 1];
	stack_b->nmemb += 1;
	stack_a->nmemb -= 1;
}

void pb(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->nmemb <= 1 || stack_a->size == stack_a->nmemb)
		return ;
	stack_a->data[stack_a->nmemb] = stack_b->data[stack_b->nmemb - 1];
	stack_b->nmemb -= 1;
}

void ra(t_stack *stack_a)
{
	int i = 0;
	int temp = stack_a->data[0];
	if (stack_a->nmemb <= 1 || stack_a->size <= 1)
		return ;
	while (i < stack_a->nmemb - 1)
	{
		stack_a->data[i] = stack_a->data[i + 1];
		i++;
	}
	stack_a->data[stack_a->nmemb - 1] = temp;
}

void rb(t_stack *stack_b)
{
	int i = 0;
	int temp = stack_b->data[0];
	if (stack_b->nmemb <= 1 || stack_b->size <= 1)
		return ;
	while (i < stack_b->nmemb - 1)
	{
		stack_b->data[i] = stack_b->data[i + 1];
		i++;
	}
	stack_b->data[stack_b->nmemb - 1] = temp;
}

void rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

void rra(t_stack *stack_a)
{
	int temp;
	int i = stack_a->nmemb;
	if (stack_a->nmemb <= 1 || stack_a->size <= 1)
		return ;
	temp = stack_a->data[stack_a->nmemb-1];
	while (i > 0)
	{
		stack_a->data[i] = stack_a->data[i - 1];
		i--;
	}
	stack_a->data[0] = temp;
}

void rrb(t_stack *stack_b)
{
	int temp;
	int i = stack_b->nmemb;
	if (stack_b->nmemb <= 1 || stack_b->size <= 1)
		return ;
	temp = stack_b->data[stack_b->nmemb-1];
	while (i > 0)
	{
		stack_b->data[i] = stack_b->data[i - 1];
		i--;
	}
	stack_b->data[0] = temp;
}

void rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}

