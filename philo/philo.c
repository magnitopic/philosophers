/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:06:33 by alaparic          #+#    #+#             */
/*   Updated: 2023/05/11 17:42:59 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_philo	*create_philos(t_data *data)
{
	t_philo	*philos;
	int		i;

	philos = malloc(sizeof(t_philo) * data->n_philos);
	if (!philos)
		return (NULL);
	i = 0;
	while (data->n_philos > i)
	{
		philos[i].pos = i + 1;
		philos[i].times_eaten = 0;
	}
	return (philos);
}

static int	start_data(char **argv, t_data *data)
{
	data->n_philos = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->n_eat = ft_atoi(argv[5]);
	else
		data->n_eat = 0;
	data->philos = create_philos(data);
	if (!data->philos)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	(void)argv;
	if (error_check(argc, argv))
		return (1);
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	if (!start_data(argv, data))
		return (1);
	return (0);
}
