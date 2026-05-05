/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_s_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainarako <ainarako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 15:48:54 by ainarako          #+#    #+#             */
/*   Updated: 2026/04/23 15:49:05 by ainarako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "bench.h"

void	bench_sa(t_bench *bench)
{
	bench->sa++;
}

void	bench_sb(t_bench *bench)
{
	bench->sb++;
}

void	bench_ss(t_bench *bench)
{
	bench->ss++;
}

int	get_total_ops(t_bench *bench)
{
	int	total;

	total = bench->sa + bench->sb + bench->ss;
	total += bench->pa + bench->pb;
	total += bench->ra + bench->rb + bench->rr;
	total += bench->rra + bench->rrb + bench->rrr;
	return (total);
}

char	*get_strategy_name(char *flag, float disorder, int size)
{
	if (flag)
	{
		if (!ft_strcmp(flag, "--simple"))
			return ("Simple / selection");
		if (!ft_strcmp(flag, "--medium"))
			return ("Medium / chunks");
		if (!ft_strcmp(flag, "--complex"))
			return ("Complex / radix");
		if (!ft_strcmp(flag, "--adaptive"))
			return ("Adaptive / mixed");
	}
	if (size <= 5)
		return ("Adaptive / simple");
	if (disorder < 0.08)
		return ("Adaptive / low disorder");
	if (size <= 200 || disorder < 0.65)
		return ("Adaptive / chunks");
	return ("Adaptive / radix");
}

float	compute_disorder(t_list **a)
{
	int		total;
	int		inversions;
	t_list	*i;
	t_list	*j;

	total = ft_lstsize(*a);
	if (total <= 1)
		return (0.0);
	inversions = 0;
	i = *a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value > j->value)
				inversions++;
			j = j->next;
		}
		i = i->next;
	}
	return ((float)inversions / (total * (total - 1) / 2));
}

void	exec_algo(char *flag, t_list **a, t_list **b, t_bench *bench)
{
	g_current_bench = bench;
	if (!ft_strcmp(flag, "--simple"))
		simple_sort(a, b);
	else if (!ft_strcmp(flag, "--medium"))
		medium_sort(a, b);
	else if (!ft_strcmp(flag, "--complex"))
		radix_sort(a, b);
	else
		adaptive_sort(a, b);
	g_current_bench = NULL;
}
