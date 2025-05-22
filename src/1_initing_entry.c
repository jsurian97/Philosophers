/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_initing_entry.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 22:12:09 by jsurian           #+#    #+#             */
/*   Updated: 2025/05/08 16:05:23 by jsurian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*securecheck(char *str)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (str[i + y] == '0' && str[i + y + 1] != '\0')
		y++;
	while (str[i + y] != '\0')
	{
		if (str[i + y] < '0' || str[i + y] > '9')
			return (NULL);
		i++;
	}
	if (i > 10)
		return (NULL);
	return (str);
}

long	ft_atoi(char *str)
{
	long	i;
	long	resultat;

	i = 0;
	resultat = 0;
	if (str == NULL)
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		resultat = resultat * 10 + str[i] - '0';
		i++;
	}
	if (resultat == 0)
		return (-1);
	return (resultat);
}

int	testing(t_param *param)
{
	if (param->nb_philos > 200 || param->nb_philos == -1)
		return (1);
	if (param->t_died > INT_MAX || param->t_died == -1)
		return (1);
	if (param->t_eat > INT_MAX || param->t_eat == -1)
		return (1);
	if (param->t_sleep > INT_MAX || param->t_sleep == -1)
		return (1);
	if (param->nboftimes > INT_MAX || param->nboftimes == -1)
		return (1);
	return (0);
}

int	filling(t_param *param, int argc, char **argv)
{
	param->nb_philos = ft_atoi(securecheck(argv[1]));
	param->t_died = ft_atoi(securecheck(argv[2]));
	param->t_eat = ft_atoi(securecheck(argv[3]));
	param->t_sleep = ft_atoi(securecheck(argv[4]));
	if (argc == 6)
		param->nboftimes = ft_atoi(securecheck(argv[5]));
	else
		param->nboftimes = 0;
	param->start =  getime(0) + 10;
	return (testing(param));
}

int	initing_entry(t_param *param, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (1);
	if (filling(param, argc, argv))
		return (1);
	return (0);
}
