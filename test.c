#include "push_swap.h"

int main(int ac, char **av)
{
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // une array en exemp
    int array2[10];

    t_stack *stack_a = malloc(sizeof(t_stack));
    stack_a->data = array;
    stack_a->head = 0;
    stack_a->nmemb = 9;
    
    t_stack *stack_b = malloc(sizeof(t_stack));
    stack_b->data = array2;
    stack_b->head = 0;
    stack_b->nmemb = 0;


    rrr(stack_a, stack_b);
    rrr(stack_a, stack_b);
    rrr(stack_a, stack_b);
    print_stack(*stack_a);
    print_stack(*stack_b);
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
    print_stack(*stack_a);
    print_stack(*stack_b);
}