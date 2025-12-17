/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondra <tigondra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:55:58 by tigondra          #+#    #+#             */
/*   Updated: 2025/12/17 18:24:03 by tigondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_bench(t_bench *bench)
{
	bench->ops = 0;
	bench->disorder = 0;
	bench->strat = 0;
	bench->comp = 0;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
}

char	*ft_get_strat(int strat)
{
	char	str;

	if (strat == 1)
		str = "Simple";
	else if (strat == 2)
		str = "Medium";
	else if (strat == 3)
		str = "Complex";
	else if (strat == 4)
		str = "Adaptive";
	else
		str = "Error";
	return (str);
}

char	*comp(int comp)
{
	char	str;

	if (comp == 1)
		str = "O(n2)";
	else if (comp == 2)
		str = "O(n√n)";
	else if (comp == 3)
		str = "O(n log n)";
	else
		str = "Error";
	return (str);
}

void	create_benchmark(t_bench *bench)
{
	ft_printf("[bench] disorder: %d%%\n", bench->disorder);
	ft_printf("[bench] strategy: %s", ft_get_strat(bench->strat));
	ft_printf(" / %s\n", ft_get_comp(bench->comp));
	ft_printf("[bench] total_ops: %d\n", bench->ops);
	ft_printf("[bench] ");
	ft_printf("sa: %d sb: %d ss: %d ", bench->sa, bench->sb, bench->ss);
	ft_printf("pa: %d pb: %d\n", bench->pa, bench->pb);
	ft_printf("ra: %d rb: %d rr: %d ", bench->ra, bench->rb, bench->rr);
	ft_printf("rra: %d rrb: %d rrr: %d\n", bench->rra, bench->rrb, bench->rrr);
}
