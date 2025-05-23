/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_initing_philos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian <jsurian@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:04:54 by jsurian           #+#    #+#             */
/*   Updated: 2025/05/08 18:10:11 by jsurian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

//check les mutex init ?

int	initing_philos(t_param *param)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&param->mutex_print, NULL))
		return (1);
	if (pthread_mutex_init(&param->mutex_dying, NULL))
	{
		pthread_mutex_destroy(&param->mutex_print);
		return (1);
	}
	while (i < param->nb_philos)
	{
		param->philos[i].id_philos = i;
		param->philos[i].start_meal = 0;
		param->philos[i].nbofeat = param->nboftimes;
		param->philos[i].fork = 0;
		if (pthread_mutex_init(&param->philos[i].mutex_fork, NULL))
		{
			param->nb_philos = i + 1;
			return (1);
		}
		param->philos[i].param = param;
		i++;
	}
	return (0);
}
