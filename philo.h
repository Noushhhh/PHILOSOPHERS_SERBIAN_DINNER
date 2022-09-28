/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandric <aandric@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 10:58:31 by aandric           #+#    #+#             */
/*   Updated: 2022/09/27 17:00:04 by aandric          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdint.h>

/* ================ ~ STRUCTURES ~ ================ */
typedef enum e_bool
{
	false,
	true
}				t_bool;

typedef struct s_data
{
	struct s_philo	**philo_array;
	pthread_mutex_t	*forks_array;
	pthread_mutex_t	end_program_perm;
	pthread_mutex_t	end_meals_perm;
	int				philo_nb;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_nb;
	t_bool			end_program;
	t_bool			end_meals;
}				t_data;

typedef struct s_philo
{
	int				id;
	t_data			*data;
	int				last_meal_time;
	int				meals_count;
	int				time_zero;
	pthread_t		thread;
	pthread_mutex_t	last_meal_perm;
	pthread_mutex_t	meals_count_perm;
}				t_philo;

/* ================ ~ UTILS ~ ================ */
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);
void	ft_usleep(unsigned int time, t_philo *philo);

/* ================ ~ PARSING ~ ================ */
t_bool	check_input(int ac, char **av);

/* ================ ~ PHILO ~ ================ */
t_philo	**philo_array_create(t_data *data);
void	philo_join_all(t_philo **philo_array);
void	philo_free(t_philo **philo_array, int philo_nb);

/* ================ ~ DATA ~ ================ */
t_data	*data_init(int ac, char **av);
void	data_free(t_data *data);

/* ================ ~ ROUTINE ~ ================ */
void	*routine(void *arg);
int		get_time(void);
void	display(t_philo *philo, const char *str);

/* ================ ~ CHECK ROUTINE ~ ================ */
t_bool	program_stop(t_philo *philo);
t_bool	meals_stop(t_philo *philo);
t_bool	philo_is_dead(t_data *data);
t_bool	all_meals_done(t_data *data);

#endif
