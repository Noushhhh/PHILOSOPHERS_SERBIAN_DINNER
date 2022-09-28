/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandric <aandric@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:04:29 by aandric           #+#    #+#             */
/*   Updated: 2022/09/28 13:31:11 by aandric          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static t_bool	is_digit(const char *str)
{
	size_t	i;	

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

static t_bool	all_positive_digits(char **av)
{
	size_t	i;

	i = 1;
	while (av[i])
	{
		if (!is_digit(av[i]) || !ft_strlen(av[i]))
			return (false);
		i++;
	}
	return (true);
}

static t_bool	integer_overflow(char **av)
{
	size_t	i;

	i = 1;
	while (av[i])
	{
		if (ft_atoi(av[i]) < 0)
			return (true);
		i++;
	}
	return (false);
}

t_bool	check_input(int ac, char **av)
{
	if (ac < 5 || ac > 6)
	{
		printf("Invalid number of arguments\n");
		return (false);
	}
	else if (!all_positive_digits(av) || av[1][0] == '0')
	{
		printf("Invalid or empty character\n");
		return (false);
	}
	if (integer_overflow(av))
	{
		printf("Integer overflow\n");
		return (false);
	}
	if (ac == 6)
	{
		if (av[5][0] == '0')
			return (false);
	}
	return (true);
}
