/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondra <tigondra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:56:02 by tigondra          #+#    #+#             */
/*   Updated: 2025/12/18 15:52:25 by tigondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_flag(const char *s)
{
	return (s && s[0] == '-' && s[1] == '-');
}

static int	ft_parse_flags(int ac, char **av, int *i, t_bench *bench)
{
	ft_init_bench(bench);
	*i = 1;
	while (*i < ac && ft_is_flag(av[*i]))
	{
		if (!ft_strcmp(av[*i], "--bench"))
			bench->enable = 1;
		else if (!ft_strcmp(av[*i], "--simple"))
			bench->strat = 1;
		else if (!ft_strcmp(av[*i], "--medium"))
			bench->strat = 2;
		else if (!ft_strcmp(av[*i], "--complex"))
			bench->strat = 3;
		else if (!ft_strcmp(av[*i], "--adaptive"))
			bench->strat = 4;
		else
			return (0);
		(*i)++;
	}
	return (1);
}

void	ft_sort(t_stack *a, t_stack *b, t_bench *bench)
{
	if (bench->strat == 1)
		ft_selection_sort(a, b, bench);
	else if (bench->strat == 2)
		ft_radix_sort(a, b, bench);
	else if (bench->strat == 3)
		ft_radix_sort(a, b, bench);
	else
		ft_adaptive_sort(a, b, bench);
}

int	ft_compute_disorder(const t_stack *a)
{
	const t_node	*i;
	const t_node	*j;
	long long		mistakes;
	long long		total_pairs;

	if (!a || a->size < 2 || !a->head)
		return (0);
	mistakes = 0;
	total_pairs = 0;
	i = a->head;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total_pairs++;
			if (i->data > j->data)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	return ((int)((mistakes * 10000) / total_pairs));
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_bench	bench;
	int		first_arg;

	if (ac < 2)
		return (0);
	if (!ft_parse_flags(ac, av, &first_arg, &bench))
		return (write(2, "Error\n", 6), 1);
	if (first_arg >= ac)
		return (0);
	a = ft_fill_stack(ac - first_arg, av + first_arg);
	if (!a)
		return (write(2, "Error\n", 6), 1);
	b = ft_init_stack(0, NULL, NULL);
	if (!b)
		return (ft_free_stack(a), write(2, "Error\n", 6), 1);
	bench.disorder = ft_compute_disorder(a);
	if (bench.disorder != 0)
	{
		ft_sort(a, b, &bench);
		if (bench.enable == 1)
			ft_create_benchmark(&bench);
	}
	return (ft_free_stacks(a, b));
}
