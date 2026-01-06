/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondra <tigondra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 13:09:22 by tigondra          #+#    #+#             */
/*   Updated: 2026/01/06 15:22:29 by tigondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_read_stdin(t_stack *a, t_stack *b)
{
    char    *str;

    str = get_next_line(0);
    while(str && str[0] != '\n')
    {
        if (ft_strcmp(str, "pa\n") == 0)
            ft_push(a,b);
        else if (ft_strcmp(str, "pb\n") == 0)
            ft_push(a,b);
        else if (ft_strcmp(str, "sa\n") == 0)
            ft_swap(a);
        else if (ft_strcmp(str, "sb\n") == 0)
            ft_swap(b);
        else if (ft_strcmp(str, "ss\n") == 0)
        {
            ft_swap(a);
            ft_swap(b);
        }
        else if (ft_strcmp(str, "ra\n") == 0)
            ft_rotate(a);
        else if (ft_strcmp(str, "rb\n") == 0)
            ft_rotate(b);
        else if (ft_strcmp(str, "rr\n") == 0)
        {
            ft_rotate(a);
            ft_rotate(b);
        }
        else if (ft_strcmp(str, "rra\n") == 0)
            ft_reverse_rotate(a);
        else if (ft_strcmp(str, "rrb\n") == 0)
            ft_reverse_rotate(b);
        else if (ft_strcmp(str, "rrr\n") == 0)
        {
            ft_reverse_rotate(a);
            ft_reverse_rotate(b);
        }
        free(str);
        str = get_next_line(0);
    }
    free(str);
}

void    print_stack(t_stack *stack)
{
    t_node    *node;
    int        i;

    i = 0;
    node = stack->head;
    if (!node)
        return ;
    ft_printf("stack : |");
    while (node->next != NULL)
    {
        ft_printf("%d|", node->data);
        node = node->next;
    }
    ft_printf("%d|", node->data);
    ft_printf("\n");
}

int is_sorted(t_stack *stack)
{
    t_node  *current;

    if (!stack || stack->size < 2)
        return (0);

    current = stack->head;
    while (current->next)
    {
        if (current->data > current->next->data)
            return (1);
        current = current->next;
    }
    return (0);
}

int main(int ac, char **av)
{
    t_stack	*a;
	t_stack	*b;
	int		first_arg;

	if (ac < 2)
		return (0);
    first_arg = 1;
	if (first_arg >= ac)
		return (0);
	a = ft_fill_stack(ac - first_arg, av + first_arg);
	if (!a)
		return (ft_error());
	b = ft_init_stack(0, NULL, NULL);
	if (!b)
		return (ft_free_stack_error(a));
    ft_read_stdin(a, b);
    print_stack(a);
    if (is_sorted(a) == 0)
        ft_printf("OK\n");
    else
    {
        ft_printf("KO\n");
    }
    return (ft_free_stacks(a, b)); 
}
