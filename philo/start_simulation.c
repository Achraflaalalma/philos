/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:48:12 by alaalalm          #+#    #+#             */
/*   Updated: 2024/05/12 15:48:19 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_simulation(t_table *table)
{
	int	i;

	table->start = get_time();
	i = -1;
	while (++i < table->number_of_philos)
	{
		if (pthread_create(&table->philo[i].thread,
				NULL, philo_life, &table->philo[i]))
			return (1);
		if (pthread_detach(table->philo[i].thread))
			return (1);
	}
	return (0);
}
