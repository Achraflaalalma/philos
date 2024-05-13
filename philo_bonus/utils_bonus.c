/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:42:55 by alaalalm          #+#    #+#             */
/*   Updated: 2024/05/12 18:40:13 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	freeall(t_table *table)
{
	sem_close(table->forks);
	sem_close(table->print);
	sem_unlink("forks");
	sem_unlink("print");
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
