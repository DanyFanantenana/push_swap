/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainarako <ainarako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 20:00:00 by faharila          #+#    #+#             */
/*   Updated: 2026/04/23 21:12:08 by ainarako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_phase(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(*a);
	while (size > 3)
	{
		pb(a, b);
		size--;
	}
}

static int	find_best_b(t_list **a, t_list **b)
{
	t_list	*head;
	int		best_idx;
	int		min_cost;
	int		cost;

	head = *b;
	best_idx = head->index;
	min_cost = get_cost(a, b, head->index);
	head = head->next;
	while (head)
	{
		cost = get_cost(a, b, head->index);
		if (cost < min_cost)
		{
			min_cost = cost;
			best_idx = head->index;
		}
		head = head->next;
	}
	return (best_idx);
}

static void	push_best_to_a(t_list **a, t_list **b)
{
	apply_move(a, b, find_best_b(a, b));
}

static void	rotate_min_to_top(t_list **a)
{
	int	dist;
	int	size;

	size = ft_lstsize(*a);
	dist = get_distance(a, 0);
	if (dist <= size / 2)
	{
		while (dist-- > 0)
			ra(a);
	}
	else
	{
		dist = size - dist;
		while (dist-- > 0)
			rra(a);
	}
}

void	turk_sort(t_list **a, t_list **b)
{
	push_phase(a, b);
	simple_sort(a, b);
	while (ft_lstsize(*b) > 0)
		push_best_to_a(a, b);
	rotate_min_to_top(a);
}
