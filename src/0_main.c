/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:57:20 by jsurian           #+#    #+#             */
/*   Updated: 2025/05/08 14:12:58 by jsurian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*

message d'erreur
alone philo
nb de fois a manger

*/

/*int	entry_error(void)
{
	printf("\nThe entries are not good\n\n");
	printf("Order of the argument without any sign:\n");
	printf("number_of_philosophers time_to_die time_to_eat time_to_sleep");
	printf(" [number_of_times_each_philosopher_must_eat]\n\n");
	printf("Number max of philos: 200\n");
	printf("Size of others entries : int\n\n");
	return (0);
}*/

/*int	philo_error(void)
{
	
	//message d'erreur creation philo -> probleme malloc ou mutex?

	return (0);
}*/

int	main(int argc, char **argv)
{
	t_param param;

	if (initing_entry(&param, argc, argv))
		return (0);
	if (initing_philos(&param))		//liberer les mutex initialiser
		return (0);
	if (starting(&param))
		return (finishing(&param.philos[0]));
	return (finishing(&param.philos[0]));
}
