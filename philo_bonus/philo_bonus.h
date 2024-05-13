/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:06:30 by alaalalm          #+#    #+#             */
/*   Updated: 2024/05/12 16:08:03 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <limits.h>
# include <stdbool.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <signal.h>

typedef struct s_philo	t_philo;
typedef struct s_table	t_table;

struct s_table
{
	long			number_of_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			nfo_each_philo_must_eat;
	long			start;
	sem_t			*forks;
	sem_t			*print;
	t_philo			*philo;
};

struct s_philo
{
	long			id;
	long			last_meal;
	long			meals;
	int				is_dead;
	t_table			*table;
};

long			ft_atoi(const char *str);
int				ft_isdigit(char c);
int				philo_life(void *philo);
void			freeall(t_table *table);
unsigned long	get_time(void);
void			ft_usleep(long ms);
void			print_status(t_philo *philo, char *status);
int				check_death(t_philo *philo);
int				initialize_data(t_table *table, char **argv);
void			init_philo(t_philo *philo, t_table *table, int i);
int				start_simulation(t_table *table);

#endif