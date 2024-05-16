/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:42:55 by alaalalm          #+#    #+#             */
/*   Updated: 2024/05/16 12:39:57 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	destroy_print(t_table *table)
{
	pthread_mutex_destroy(&table->print);
	return (1);
}

int	destroy_all(t_table *table, long i)
{
	while (--i >= 0)
		pthread_mutex_destroy(&table->forks[i]);
	pthread_mutex_destroy(&table->print);
	pthread_mutex_destroy(&table->lock);
	return (1);
}

void	freeall(t_table *table)
{
	long	i;

	i = -1;
	while (++i < table->number_of_philos)
		pthread_mutex_destroy(&table->forks[i]);
	pthread_mutex_destroy(&table->print);
	pthread_mutex_destroy(&table->lock);
	free(table->philo);
	free(table->forks);
}

unsigned long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(long ms)
{
	unsigned long	time;

	time = get_time();
	while (get_time() - time < (unsigned long)ms)
		usleep(100);
}
