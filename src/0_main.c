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

int	main(int argc, char **argv)
{
	t_param	param;

	if (initing_entry(&param, argc, argv))
		return (0);
	if (initing_philos(&param))
		return (0);
	if (starting(&param))
		return (finishing(&param.philos[0]));
	return (finishing(&param.philos[0]));
}
