/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:06:33 by alaparic          #+#    #+#             */
/*   Updated: 2023/08/21 13:23:18 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_philo	*create_philos(t_universe *data)
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
		pthread_mutex_init(&philos[i].fork_l, NULL);
		i++;
	}
	return (philos);
}

static void	start_universe(char **argv, t_universe *data)
{
	data->n_philos = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->n_eat = ft_atoi(argv[5]);
	else
		data->n_eat = 0;
	data->breaker = 0;
	//pthread_mutex_init(data->message, NULL);
}

int	main(int argc, char **argv)
{
	t_universe	*data;
	t_philo		*philos;

	(void)argv;
	if (parsing(argc, argv))
		return (1);
	data = malloc(sizeof(t_universe));
	if (!data)
		return (1);
	start_universe(argv, data);
	philos = create_philos(data);
	if (!philos)
		return (free(data) ,1);
	free(data);
	free(philos);
	return (0);
}
