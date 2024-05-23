/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:19:03 by alaalalm          #+#    #+#             */
/*   Updated: 2024/05/23 11:08:11 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_philo *philo, char *status)
{
	pthread_mutex_lock(&philo->table->print);
	printf("%ld %ld %s\n", get_time() - philo->table->start, philo->id, status);
	pthread_mutex_unlock(&philo->table->print);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	first_fork = philo->left_fork;
	second_fork = philo->right_fork;
	pthread_mutex_lock(first_fork);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(second_fork);
	print_status(philo, "has taken a fork");
	print_status(philo, "is eating");
	pthread_mutex_lock(&philo->table->lock);
	philo->last_meal = get_time();
	philo->meals++;
	pthread_mutex_unlock(&philo->table->lock);
	ft_usleep(philo->table->time_to_eat);
	pthread_mutex_unlock(first_fork);
	pthread_mutex_unlock(second_fork);
}

void	ft_sleep(t_philo *philo)
{
	print_status(philo, "is sleeping");
	ft_usleep(philo->table->time_to_sleep);
}

void	*philo_life(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	if (p->id % 2 == 0)
		ft_usleep(p->table->time_to_eat);
	while (1)
	{
		pthread_mutex_lock(&p->table->lock);
		if (p->table->nfo_each_philo_must_eat != -1
			&& p->meals == p->table->nfo_each_philo_must_eat)
		{
			pthread_mutex_unlock(&p->table->lock);
			return (NULL);
		}
		pthread_mutex_unlock(&p->table->lock);
		ft_eat(p);
		ft_sleep(p);
		print_status(p, "is thinking");
	}
	return (NULL);
}
