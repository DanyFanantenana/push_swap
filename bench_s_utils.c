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
