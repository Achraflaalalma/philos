/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:59:26 by alaalalm          #+#    #+#             */
/*   Updated: 2024/05/15 12:10:40 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	initialize_data(t_table *table, char **argv)
{
	table->number_of_philos = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	sem_unlink("forks");
	sem_unlink("print");
	sem_unlink("lock");
	table->print = sem_open("print", O_CREAT, 0666, 1);
	table->lock = sem_open("lock", O_CREAT, 0666, 1);
	table->forks = sem_open("forks", O_CREAT, 0666, table->number_of_philos);
	table->nfo_each_philo_must_eat = -1;
	if (argv[5])
		table->nfo_each_philo_must_eat = ft_atoi(argv[5]);
	if (table->number_of_philos <= 0 || table->time_to_die < 60
		|| table->time_to_eat < 60 || table->time_to_sleep < 60
		|| (argv[5] && table->nfo_each_philo_must_eat <= 0)
		|| table->number_of_philos > 200)
		return (1);
	return (0);
}

void	init_philo(t_philo *philo, t_table *table, int i)
{
	philo->id = i + 1;
	table->start = get_time();
	philo->last_meal = get_time();
	philo->meals = 0;
	philo->is_dead = 0;
	philo->table = table;
}
