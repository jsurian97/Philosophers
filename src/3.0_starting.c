/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.0_starting.c                                      :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian <jsurian@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:04:28 by jsurian           #+#    #+#             */
/*   Updated: 2025/05/23 15:20:19 by jsurian        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	eating(t_philo *philo)
{
	int	left;
	int	right;

	left = philo->id_philos;
	right = (philo->id_philos + 1) % philo->param->nb_philos;
	if (philo->id_philos % 2 == 0)
	{
		if (take_fork(philo, left) || take_fork(philo, right))
			return (1);
	}
	else
	{
		if (take_fork(philo, right) || take_fork(philo, left))
			return (1);
	}
	if (check_death(philo))
		return (1);
	print(philo, "is eating", 0);
	philo->start_meal = getime(philo->param->start);
	if (sleep_and_eat(philo, getime(philo->param->start), philo->param->t_eat))
		return (1);
	pose_fork(philo, right);
	pose_fork(philo, left);
	return (0);
}

int	sleeping(t_philo *philo)
{
	if (check_death(philo))
		return (1);
	print(philo, "is sleeping", 0);
	if (sleep_and_eat(philo, getime(philo->param->start), philo->param->t_sleep))
		return (1);
	return (0);
}

int	thinking(t_philo *philo)
{
	if (check_death(philo))
		return (1);
	print(philo, "is thinking", 0);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philosynchro(philo);
	while (philo->nbofeat != 0)
	{
		if (eating(philo))
			break ;
		philo->nbofeat--;
		if (philo->nbofeat == 0)
			break ;
		if (sleeping(philo))
			break ;
		if (thinking(philo))
			break ;
	}
	return (NULL);
}

int	starting(t_param *param)
{
	int	i;

	i = 0;
	while (i < param->nb_philos)
	{
		if (pthread_create(&param->philos[i].thread, NULL,
				routine, &param->philos[i]))
		{
			param->nb_philos = i + 1;
			break ;
		}
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
