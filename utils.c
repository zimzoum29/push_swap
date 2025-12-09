#include "push_swap.h"

void print_stack(t_stack stack) 
{ 
	int i = stack.head;
	int count = 0;
	while (count < stack.nmemb)
	{
		printf("| %d", stack.data[i%stack.nmemb]); 
		i++; 
		count++; 
	}
	printf(" |\n");
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