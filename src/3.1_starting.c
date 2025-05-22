/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.1_starting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:06:53 by jsurian           #+#    #+#             */
/*   Updated: 2025/05/08 18:51:37 by jsurian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	check_death(t_philo *philo)
{
	if (getime(philo->param->start) - philo->start_meal > philo->param->t_died)
	{
		pthread_mutex_lock(&philo->param->mutex_dying);
		philo->param->dying = philo->id_philos;
		pthread_mutex_unlock(&philo->param->mutex_dying);
	}
	pthread_mutex_lock(&philo->param->mutex_dying);
	if (philo->param->dying != -1 || philo->param->dying == -2)
	{
		if (philo->param->dying != -2)
		{
			print(philo, "is dead");
			philo->param->dying = -2;
		}
		pthread_mutex_unlock(&philo->param->mutex_dying);
		return (1);
	}
	pthread_mutex_unlock(&philo->param->mutex_dying);
	return (0);
}

int	take_fork(t_philo *philo, int i_forks)
{
	while (1)
	{
		if (check_death(philo))
			return (1);
		pthread_mutex_lock(&philo->param->philos[i_forks].mutex_fork);
		if (!philo->param->philos[i_forks].fork)
		{
			philo->param->philos[i_forks].fork = 1;
			print(philo, "has taken a fork");
			pthread_mutex_unlock(&philo->param->philos[i_forks].mutex_fork);
			break ;
		}
		pthread_mutex_unlock(&philo->param->philos[i_forks].mutex_fork);
		usleep(100);
	}
	return (0);
}

int	pose_fork(t_philo *philo, int i_forks)
{
	pthread_mutex_lock(&philo->param->philos[i_forks].mutex_fork);
	philo->param->philos[i_forks].fork = 0;
	pthread_mutex_unlock(&philo->param->philos[i_forks].mutex_fork);
	return (0);
}

int	sleep_and_eat(t_philo *philo, time_t start_action)
{
	while (getime(philo->param->start) - start_action < philo->param->t_eat)
	{
		if (check_death(philo))
			return (1);
		usleep(100);
	}
	return (0);
}
