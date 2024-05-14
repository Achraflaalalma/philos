/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:47:24 by alaalalm          #+#    #+#             */
/*   Updated: 2024/05/14 23:39:46 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	all_full(t_table *table, int *set)
{
	long	i;

	i = -1;
	while (++i < table->number_of_philos)
	{
		if (table->philo[i].meals < table->nfo_each_philo_must_eat)
			return (0);
	}
	*set = 1;
	return (1);
}

int	loop_over_philos(t_table *table)
{
	long	i;

	i = -1;
	while (++i < table->number_of_philos)
	{
		pthread_mutex_lock(&table->lock);
		if (get_time() - table->philo[i].last_meal
			> (unsigned long)table->time_to_die)
		{
			pthread_mutex_unlock(&table->lock);
			pthread_mutex_lock(&table->print);
			printf("%ld %ld died\n", get_time()
				- table->start, table->philo[i].id);
			return (1);
		}
		pthread_mutex_unlock(&table->lock);
	}
	return (0);
}

int	check_death(t_table *table)
{
	int		set;

	while (1)
	{
		pthread_mutex_lock(&table->lock);
		set = 0;
		if (table->nfo_each_philo_must_eat != -1 && all_full(table, &set))
		{
			pthread_mutex_unlock(&table->lock);
			return (0);
		}
		pthread_mutex_unlock(&table->lock);
		if (loop_over_philos(table))
			return (1);
	}
	return (0);
}
