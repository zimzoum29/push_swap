#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#define test printf("test\n");

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_stack {
    int *data; // Contenu
    int size; // Taille totale
	int nmemb; // Nombre d'elements
} t_stack;

//
void print_stack(t_stack stack);
void putstr(char *str);
//

void sa(t_stack *stack_a);
void sb(t_stack *stack_b);
void ss(t_stack *stack_a, t_stack *stack_b);

void pa(t_stack *stack_a, t_stack *stack_b);
void pb(t_stack *stack_a, t_stack *stack_b);

void ra(t_stack *stack_a);
void rb(t_stack *stack_b);
void rr(t_stack *stack_a, t_stack *stack_b);

void rra(t_stack *stack_a);
void rrb(t_stack *stack_b);
void rrr(t_stack *stack_a, t_stack *stack_b);

void selection_sort(t_stack *stack_a, t_stack *stack_b);
void ra2(t_stack *stack_a, t_stack *stack_b);

#endif