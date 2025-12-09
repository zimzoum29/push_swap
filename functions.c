#include "push_swap.h"

void sa(t_stack *stack_a)
{
    int top;
    int next;
    int temp;

    if (stack_a->nmemb <= 1)
        return;
    top = (stack_a->head + stack_a->nmemb - 1) % stack_a->nmemb;
    next = (top + stack_a->nmemb - 1) % stack_a->nmemb;
    temp = stack_a->data[top];
    stack_a->data[top] = stack_a->data[next];
    stack_a->data[next] = temp;
}

void sb(t_stack *stack_b)
{
    int top;
    int next;
    int temp;

    if (stack_b->nmemb <= 1)
        return;
    top = (stack_b->head + stack_b->nmemb - 1) % stack_b->nmemb;
    next = (top + stack_b->nmemb - 1) % stack_b->nmemb;
    temp = stack_b->data[top];
    stack_b->data[top] = stack_b->data[next];
    stack_b->data[next] = temp;
}

void ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

// Push top de B vers A
void pa(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_b->nmemb < 1)
        return;

    // On décrémente head de A pour créer le nouveau top
    stack_a->head = (stack_a->head == 0) ? stack_a->nmemb : stack_a->head - 1;

    // Calcul de l'indice physique du top de B
    int top_b = (stack_b->head + stack_b->nmemb - 1) % stack_b->nmemb;

    // Placer la valeur de B sur le top de A
    stack_a->data[stack_a->head] = stack_b->data[top_b];

    stack_a->nmemb += 1;
    stack_b->nmemb -= 1;
}

// Push top de A vers B
void pb(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a->nmemb < 1)
        return;

    // On décrémente head de B pour créer le nouveau top
    stack_b->head = (stack_b->head == 0) ? stack_b->nmemb : stack_b->head - 1;

    // Calcul de l'indice physique du top de A
    int top_a = (stack_a->head + stack_a->nmemb - 1) % stack_a->nmemb;

    // Placer la valeur de A sur le top de B
    stack_b->data[stack_b->head] = stack_a->data[top_a];

    stack_b->nmemb += 1;
    stack_a->nmemb -= 1;
}


void ra(t_stack *stack_a)
{
	stack_a->head = (stack_a->head + 1) % stack_a->nmemb;
}

void rb(t_stack *stack_b)
{
	stack_b->head = (stack_b->head + 1) % stack_b->nmemb;
}

void rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

void rra(t_stack *stack_a)
{
	if (stack_a->head == 0)
		stack_a->head = stack_a->nmemb - 1;
	else
		stack_a->head--;
}

void rrb(t_stack *stack_b)
{
	if (stack_b->head == 0)
		stack_b->head = stack_b->nmemb - 1;
	else
		stack_b->head--;
}

void rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}

