/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:00:04 by alaalalm          #+#    #+#             */
/*   Updated: 2024/05/19 18:21:31 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	philo_full(t_philo *philo)
{
	if (philo->meals < philo->table->nfo_each_philo_must_eat)
		return (0);
	return (1);
}

int	check_death(t_philo *philo)
{
	while (1)
	{
		sem_wait(philo->table->lock);
		if (philo->table->nfo_each_philo_must_eat != -1 && philo_full(philo))
		{
			sem_post(philo->table->lock);
			exit(EXIT_SUCCESS);
		}
		sem_post(philo->table->lock);
		sem_wait(philo->table->lock);
		if (get_time() - philo->last_meal
			> (unsigned long)philo->table->time_to_die)
		{
			sem_post(philo->table->lock);
			sem_wait(philo->table->print);
			printf("%ld %ld died\n", get_time() - philo->table->start,
				philo->id);
			exit(EXIT_FAILURE);
		}
		sem_post(philo->table->lock);
		usleep(100);
	}
}
