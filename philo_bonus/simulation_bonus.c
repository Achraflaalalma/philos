/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:00:40 by alaalalm          #+#    #+#             */
/*   Updated: 2024/05/16 12:38:49 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	wait_pids(pid_t *pid, int n_philos)
{
	int	i;
	int	status;

	waitpid(-1, &status, 0);
	if (status != 0)
	{
		i = -1;
		while (++i < n_philos)
			kill(pid[i], SIGKILL);
	}
	else
	{
		i = -1;
		while (++i < n_philos)
			waitpid(pid[i], &status, 0);
	}
}

int	start_simulation(t_table *table)
{
	int		i;
	pid_t	*pid;

	pid = malloc(sizeof(pid_t) * table->number_of_philos);
	if (!pid)
		return (1);
	table->philo = malloc(sizeof(t_philo) * table->number_of_philos);
	if (!table->philo)
	{
		free(pid);
		return (1);
	}
	i = -1;
	while (++i < table->number_of_philos)
	{
		init_philo(table->philo + i, table, i);
		pid[i] = fork();
		if (pid[i] < 0)
			return (1);
		if (pid[i] == 0)
			philo_life(table->philo + i);
	}
	wait_pids(pid, table->number_of_philos);
	(1) && (free(pid), free(table->philo), i = -1);
	return (0);
}
