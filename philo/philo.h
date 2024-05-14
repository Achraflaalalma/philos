/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:06:30 by alaalalm          #+#    #+#             */
/*   Updated: 2024/05/14 14:55:33 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <limits.h>
# include <stdbool.h>

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
	int				philo_died;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	lock;
	pthread_mutex_t	death;
};

struct s_philo
{
	long			id;
	long			last_meal;
	long			meals;
	int				is_dead;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_table			*table;
};

int				ft_isdigit(char c);
int				check_death(t_table *table);
int				initialize_data(t_table *table, char **argv);
int				init_philo(t_table *table);
void			*philo_life(void *philo);
void			freeall(t_table *table);
void			print_status(t_philo *philo, char *status);
void			ft_usleep(long ms);
long			ft_atoi(const char *str);
unsigned long	get_time(void);
int				start_simulation(t_table *table);
#endif