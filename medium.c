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
#include <math.h>
#include <limits.h>

static int	get_chunk_size(int size)
{
	int	chunk;

	chunk = (int)sqrt((double)size);
	if (chunk < 1)
		chunk = 1;
	return (chunk);
}

static void	push_chunk_to_b(t_list **stack_a, t_list **stack_b,
	int chunk_min, int chunk_max)
{
	int	size;
	int	j;

	size = ft_lstsize(*stack_a);
	j = 0;
	while (j < size)
	{
		if ((*stack_a)->index >= chunk_min && (*stack_a)->index <= chunk_max)
		{
			pb(stack_a, stack_b);
		}
		else
		{
			ra(stack_a);
		}
		j++;
	}
}

static void	push_back_sorted(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	j;

	while (ft_lstsize(*stack_b) > 0)
	{
		size = ft_lstsize(*stack_b);
		j = 0;
		while (j < size)
		{
			if (ft_lstsize(*stack_b) > 0 && (*stack_b)->index == 0)
			{
				pa(stack_a, stack_b);
				ra(stack_a);
			}
			else if (ft_lstsize(*stack_b) > 0)
			{
				rb(stack_b);
			}
			j++;
		}
		if (ft_lstsize(*stack_b) > 0)
			break ;
	}
}

void	medium_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	chunk_size;
	int	i;
	int	chunk_min;
	int	chunk_max;

	size = ft_lstsize(*stack_a);
	chunk_size = get_chunk_size(size);
	i = 0;
	while (i < size)
	{
		chunk_min = i;
		if (i + chunk_size < size)
			chunk_max = i + chunk_size - 1;
		else
			chunk_max = size - 1;
		push_chunk_to_b(stack_a, stack_b, chunk_min, chunk_max);
		i += chunk_size;
	}
	push_back_sorted(stack_a, stack_b);
}
