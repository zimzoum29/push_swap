#include "push_swap.h"

void print_stack(t_stack stack)
{
	int i = 0;

	printf("stack : |");
	while (i < stack.nmemb)
	{
		printf("%d |", stack.data[i]);
		i++;
	}
	while (i < stack.size)
	{
		printf("  |");
		i++;
	}
	printf("\n");
}

void putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}