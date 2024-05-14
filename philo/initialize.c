/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:46:04 by alaalalm          #+#    #+#             */
/*   Updated: 2024/05/14 23:40:00 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(t_table *table)
{
	long	i;

	table->philo = malloc(sizeof(t_philo) * table->number_of_philos);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->number_of_philos);
	if (!table->forks || !table->philo)
		return (1);
	i = -1;
	while (++i < table->number_of_philos)
	{
		if (pthread_mutex_init(&table->forks[i], NULL))
			return (1);
	}
	i = -1;
	while (++i < table->number_of_philos)
	{
		(1) && (table->philo[i].id = i + 1, table->philo[i].meals = 0);
		table->philo[i].last_meal = get_time();
		table->philo[i].is_dead = 0;
		table->philo[i].left_fork = &table->forks[i];
		table->philo[i].right_fork = &table->forks[(i + 1)
			% table->number_of_philos];
		table->philo[i].table = table;
	}
	return (0);
}

int	initialize_data(t_table *table, char **argv)
{
	table->number_of_philos = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	table->nfo_each_philo_must_eat = -1;
	if (argv[5])
		table->nfo_each_philo_must_eat = ft_atoi(argv[5]);
	if (table->number_of_philos <= 0 || table->time_to_die < 60
		|| table->time_to_eat < 60 || table->time_to_sleep < 60
		|| (argv[5] && table->nfo_each_philo_must_eat <= 0)
		|| table->number_of_philos > 200)
	{
		freeall(table);
		return (1);
	}
	if (pthread_mutex_init(&table->print, NULL))
		return (1);
	if (pthread_mutex_init(&table->lock, NULL))
	{
		pthread_mutex_destroy(&table->print);
		return (1);
	}
	return (0);
}
