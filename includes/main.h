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

typedef struct	s_philo
{
	int				id_philos;				//ok
	time_t			time_meal;				//ok
	pthread_t		thread;					//ok
	int				fork;					//ok
	pthread_mutex_t	mutex_fork;				//ok
	struct s_param	*param;					//ok
}	t_philo;

typedef struct s_param						//init
{
	int				nb_philos;				//ok
	time_t			t_died;		//ms		//ok
	time_t			t_eat;		//ms		//ok
	time_t			t_sleep;	//ms		//ok
	long			nboftimes;				//ok
	time_t			start;		//ms		//ok
	t_philo 		philos[200];			//
	pthread_mutex_t	mutex_dying;			//
	int				dying;					//
	pthread_mutex_t	mutex_print;			//
}	t_param;

int	initing_entry(t_param *param, int argc, char **argv);
int	initing_philos(t_param *param);
int	starting(t_param *param);
int	finishing(t_philo *philo);

//starting 3.1
int	check_death(t_philo *philo);
int	take_fork(t_philo *philo, int i_forks);
int	pose_fork(t_philo *philo, int i_forks);
int	sleep_and_eat(t_philo *philo, time_t start_action);

//utils
int		philosynchro(t_philo *philo);
time_t	getime(time_t start);
int		print(t_philo *philo, char *message);

#endif
