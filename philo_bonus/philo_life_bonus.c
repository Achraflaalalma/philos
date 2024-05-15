/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:19:03 by alaalalm          #+#    #+#             */
/*   Updated: 2024/05/15 13:00:07 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_status(t_philo *philo, char *status)
{
	sem_wait(philo->table->print);
	printf("%ld %ld %s\n", get_time() - philo->table->start, philo->id, status);
	sem_post(philo->table->print);
}

void	ft_eat(t_philo *philo)
{
	sem_wait(philo->table->forks);
	sem_wait(philo->table->forks);
	print_status(philo, "has taken a fork");
	print_status(philo, "has taken a fork");
	print_status(philo, "is eating");
	ft_usleep(philo->table->time_to_eat);
	philo->last_meal = get_time();
	philo->meals++;
	sem_post(philo->table->forks);
	sem_post(philo->table->forks);
}

void	ft_sleep(t_philo *philo)
{
	print_status(philo, "is sleeping");
	ft_usleep(philo->table->time_to_sleep);
}

int	philo_life(void *philo)
{
	t_philo		*p;
	pthread_t	death;

	p = (t_philo *)philo;
	pthread_create(&death, NULL, (void *)check_death, p);
	while (1)
	{
		if (p->table->nfo_each_philo_must_eat != -1
			&& p->meals == p->table->nfo_each_philo_must_eat)
			return (EXIT_SUCCESS);
		ft_eat(p);
		ft_sleep(p);
		print_status(p, "is thinking");
	}
	return (EXIT_FAILURE);
}
