/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandric <aandric@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 10:58:20 by aandric           #+#    #+#             */
/*   Updated: 2022/09/28 13:33:21 by aandric          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (!check_input(ac, av))
		return (0);
	data = data_init(ac, av);
	if (!data)
		return (0);
	data->philo_array = philo_array_create(data);
	if (!data->philo_array)
	{
		data_free(data);
		free(data);
		return (0);
	}
	while (!philo_is_dead(data) && !all_meals_done(data))
		;
	philo_join_all(data->philo_array);
	data_free(data);
	return (0);
}
