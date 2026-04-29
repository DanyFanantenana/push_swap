/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faharila <faharila@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 14:07:16 by faharila          #+#    #+#             */
/*   Updated: 2026/04/23 14:07:16 by faharila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "bench.h"

static int	find_min_index(t_list **stack)
{
	t_list	*head;
	int		min_idx;

	head = *stack;
	min_idx = head->index;
	while (head)
	{
		if (head->index < min_idx)
			min_idx = head->index;
		head = head->next;
	}
	return (min_idx);
}

static void	solve_low_disorder(t_list **stack_a, t_list **stack_b)
{
	int	min_idx;
	int	distance;

	while (ft_lstsize(*stack_a) > 0)
	{
		min_idx = find_min_index(stack_a);
		distance = get_distance(stack_a, min_idx);
		make_top(stack_a, distance);
		pb(stack_a, stack_b);
	}
	while (ft_lstsize(*stack_b) > 0)
		pa(stack_a, stack_b);
}

void	adaptive_sort(t_list **stack_a, t_list **stack_b)
{
	float	disorder;

	disorder = compute_disorder(stack_a);
	if (disorder < 0.2)
		solve_low_disorder(stack_a, stack_b);
	else if (disorder < 0.5)
		medium_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

void	ft_adaptive_algo(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	g_current_bench = bench;
	adaptive_sort(stack_a, stack_b);
}
