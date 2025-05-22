/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:45:42 by jsurian           #+#    #+#             */
/*   Updated: 2025/05/08 17:54:47 by jsurian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	philosynchro(t_philo *philo)
{
	while (getime(philo->param->start) < 0)
	{
		usleep(10);
	}
	philo->time_meal = getime(philo->param->start);	
	return (0);
}

time_t	getime(time_t start)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_usec / 1000 + tv.tv_sec * 1000) - start);
}

int	print(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->param->mutex_print);
	if (philo->param->dying == -1)
		printf("%ld %d %s\n", getime(philo->param->start),
			philo->id_philos + 1, message);
	else
		printf("%ld %d %s\n", getime(philo->param->start),
			philo->param->dying + 1, message);
	pthread_mutex_unlock(&philo->param->mutex_print);
	return (0);
}
