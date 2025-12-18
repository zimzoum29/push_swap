/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondra <tigondra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:25:09 by tigondra          #+#    #+#             */
/*   Updated: 2025/12/18 15:37:45 by tigondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_adaptive_sort(t_stack *a, t_stack *b, t_bench *bench)
{
	if (bench->disorder < 2000)
		ft_selection_sort(a, b, bench);
	else if (bench->disorder < 5000)
		ft_radix_sort(a, b, bench);
	else
		ft_radix_sort(a, b, bench);
	bench->strat = 4;
}
