/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   4_finishing.c                                      :+:      :+:    :+:   */
/*                                                      +:+                   */
/*   By: jsurian <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/04/24 13:57:14 by jsurian        #+#    #+#                */
/*   Updated: 2025/05/07 18:28:24 by jsurian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	finishing(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->param->nb_philos)
	{
		pthread_mutex_destroy(&philo->param->philos[i].mutex_fork);
		i++;
	}
	pthread_mutex_destroy(&philo->param->mutex_dying);
	pthread_mutex_destroy(&philo->param->mutex_print);
	return (0);
}
