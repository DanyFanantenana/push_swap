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

static int	parse_int_digits(char *str, int i, int sign, long *value);

static int	parse_int(char *str, long *value)
{
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	if (!str || !str[0])
		return (0);
	if (str[i] == '+')
		return (0);
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (!str[i])
		return (0);
	return (parse_int_digits(str, i, sign, value));
}

static int	parse_int_digits(char *str, int i, int sign, long *value)
{
	long	n;

	n = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		n = (n * 10) + (str[i++] - '0');
		if ((sign == 1 && n > 2147483647)
			|| (sign == -1 && n > 2147483648))
			return (0);
	}
	*value = n * sign;
	return (1);
}

static int	has_duplicate(char **args, int i, long value)
{
	long	current;

	i++;
	while (args[i])
	{
		if (!parse_int(args[i], &current))
			return (0);
		if (current == value)
			return (1);
		i++;
	}
	return (0);
}

static int	is_empty_arg(char *arg)
{
	int	i;

	i = 0;
	if (!arg)
		return (1);
	while (arg[i])
	{
		if (arg[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

static void	args_error(char **args, int must_free)
{
	if (must_free)
		ft_free(args);
	ft_error();
}

static char	**get_args(int argc, char **argv, int *i)
{
	char	**args;

	*i = 1;
	args = argv;
	if (argc == 2)
	{
		if (is_empty_arg(argv[1]))
			ft_error();
		args = ft_split(argv[1], ' ');
		if (!args || !args[0])
			args_error(args, args != NULL);
		*i = 0;
	}
	return (args);
}

void	ft_check_args(int argc, char **argv)
{
	int		i;
	long	value;
	char	**args;

	args = get_args(argc, argv, &i);
	while (args[i])
	{
		if (!parse_int(args[i], &value) || has_duplicate(args, i, value))
			args_error(args, argc == 2);
		i++;
	}
	if (argc == 2)
		ft_free(args);
}

void	initstack(t_list **stack, int argc, char **argv)
{
	t_list	*new;
	char	**args;
	int		i;

	args = get_args(argc, argv, &i);
	while (args[i])
	{
		new = ft_lstnew((int)ft_atoi(args[i++]));
		if (!new)
			ft_error();
		ft_lstadd_back(stack, new);
	}
	index_stack(stack);
	if (argc == 2)
		ft_free(args);
}
