/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faharila <faharila@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 08:40:50 by faharila          #+#    #+#             */
/*   Updated: 2026/04/22 08:40:50 by faharila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_contains(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_check_args(int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**args;

	if (argc == 2)
		i = 0;
	else
		i = 1;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv;
	/* while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (!ft_isnum(args[i]))
			ft_error();
		if (ft_contains(tmp, args, i))
			ft_error();
		if (tmp < -2147483648 || tmp > 2147483647)
			ft_error();
		i++;
	}
	if (argc == 2)
		ft_free(args); */
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (!ft_isnum(args[i]) || ft_contains(tmp, args, i) || tmp < -2147483648 || tmp > 2147483647)
		{
			if (argc == 2) // ← free args AVANT ft_error()
				ft_free(args);
			ft_error();
		}
		i++;
	}
}

void	initstack(t_list **stack, int argc, char **argv)
{
	t_list	*new;
	char	**args;
	int		i;

	if (argc == 2)
		i = 0;
	else
		i = 1;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv;
	while (args[i])
	{
		new = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	index_stack(stack);
	if (argc == 2)
		ft_free(args);
}
