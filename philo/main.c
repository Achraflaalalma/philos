/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:06:00 by alaalalm          #+#    #+#             */
/*   Updated: 2024/05/14 15:59:50 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc != 5 && argc != 6)
		return (0);
	if (initialize_data(&table, argv))
		return (1);
	if (init_philo(&table))
	{
		freeall(&table);
		return (2);
	}
	if (start_simulation(&table))
	{
		freeall(&table);
		return (3);
	}
	check_death(&table);
	freeall(&table);
	return (0);
}
