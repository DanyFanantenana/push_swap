/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_p_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainarako <ainarako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 15:48:45 by ainarako          #+#    #+#             */
/*   Updated: 2026/04/23 15:48:46 by ainarako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include "bench.h"

void	bench_pa(t_bench *bench)
{
	bench->pa++;
}

void	bench_pb(t_bench *bench)
{
	bench->pb++;
}

void	bench_rrr(t_bench *bench)
{
	bench->rrr++;
}
