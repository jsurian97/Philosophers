/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:58:30 by jsurian           #+#    #+#             */
/*   Updated: 2025/05/08 18:10:23 by jsurian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

struct	s_param;

typedef struct s_philo
{
	int				id_philos;
	time_t			start_meal;
	int				nbofeat;
	pthread_t		thread;
	int				fork;
	pthread_mutex_t	mutex_fork;
	struct s_param	*param;
}	t_philo;

typedef struct s_param
{
	int				nb_philos;
	time_t			t_died;
	time_t			t_eat;
	time_t			t_sleep;
	long			nboftimes;
	time_t			start;
	t_philo			philos[200];
	pthread_mutex_t	mutex_dying;
	int				dying;
	pthread_mutex_t	mutex_print;
	int				print;
}	t_param;

int		initing_entry(t_param *param, int argc, char **argv);
int		initing_philos(t_param *param);
int		starting(t_param *param);
int		finishing(t_param *param);

//starting 3.1
int		check_death(t_philo *philo);
int		take_fork(t_philo *philo, int i_forks);
int		pose_fork(t_philo *philo, int i_forks);
int		sleep_and_eat(t_philo *philo, time_t start_action, time_t sleep_or_eat);

//utils
int		philosynchro(t_philo *philo);
time_t	getime(time_t start);
int		print(t_philo *philo, char *message, int last);

#endif
