/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faharila <faharila@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 19:30:00 by faharila          #+#    #+#             */
/*   Updated: 2026/04/22 07:10:55 by faharila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk_size(int size)
{
	if (size <= 100)
		return (15);
	return (35);
}

static int	find_max_index(t_list **stack)
{
	t_list	*head;
	int		max;

	head = *stack;
	max = head->index;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	return (max);
}

static void	push_to_b(t_list **a, t_list **b, int chunk)
{
	int	pushed;

	pushed = 0;
	while (*a)
	{
		if ((*a)->index <= pushed)
		{
			pb(a, b);
			rb(b);
			pushed++;
		}
		else if ((*a)->index <= pushed + chunk)
		{
			pb(a, b);
			pushed++;
		}
		else
			ra(a);
	}
}

static void	push_max_to_a(t_list **a, t_list **b)
{
	int	max;
	int	distance;
	int	size;

	max = find_max_index(b);
	distance = get_distance(b, max);
	size = ft_lstsize(*b);
	if (distance <= size / 2)
		while (distance-- > 0)
			rb(b);
	else
		while (distance++ < size)
			rrb(b);
	pa(a, b);
}

void	medium_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size <= 5)
	{
		simple_sort(stack_a, stack_b);
		return ;
	}
	push_to_b(stack_a, stack_b, get_chunk_size(size));
	while (*stack_b)
		push_max_to_a(stack_a, stack_b);
}
