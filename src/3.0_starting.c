/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.0_starting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian <jsurian@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:04:28 by jsurian           #+#    #+#             */
/*   Updated: 2025/05/08 18:05:41 by jsurian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	eating(t_philo *philo)
{
	int left;
	int right;
	
	left = philo->id_philos;
	//printf("fork id : %d\n", left);
	right = (philo->id_philos + 1) % philo->param->nb_philos;
	//printf("right fork : %d\n", right);
	if (philo->id_philos % 2 == 0)
	{
		if (take_fork(philo, left))
			return (1);
		if (take_fork(philo, right))
			return (1);
	}
	else
	{
		if (take_fork(philo, right))
			return (1);
		if (take_fork(philo, left))
			return (1);
	}
	//print(philo, "is eating");
	philo->time_meal = getime(philo->param->start);
	//printf("time meal avec sleep : %ld\n", getime(philo->param->start));
	if (sleep_and_eat(philo, getime(philo->param->start)))
		return (1);
	pose_fork(philo, right);
	pose_fork(philo, left);
	return (0);
}

int	sleeping(t_philo *philo)
{
	print(philo, "is sleeping");
	if (sleep_and_eat(philo, getime(philo->param->start)))
		return (1);
	return (0);
}
int	thinking(t_philo *philo)
{
	print(philo, "is thinking");
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo*)arg;
	philosynchro(philo);
	while (1)
	{
		if (eating(philo))
			break;
		if (sleeping(philo))
			break;
		if (thinking(philo))
			break;
	}
	return NULL;
}

int	starting(t_param *param)
{
	int	i;

	i = 0;
	while (i < param->nb_philos)
	{
		pthread_create(&param->philos[i].thread, NULL, routine, &param->philos[i]);
		i++;
	}
	i = 0;
	while (i < param->nb_philos)
	{
		pthread_join(param->philos[i].thread, NULL);
		i++;
	}
	return (0);
}
