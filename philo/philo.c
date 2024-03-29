/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:06:33 by alaparic          #+#    #+#             */
/*   Updated: 2023/09/22 07:58:12 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	handle_one_philo(t_universe *data)
{
	long	time;

	time = get_current_time() - data->start_time;
	print_message(&data->philos[0], FORK, time);
	ft_usleep(data->t_die);
	printf(COMMON, data->t_die, data->philos[0].pos);
	printf(DIE_MESSAGE);
}

static t_philo	*create_philos(t_universe *data)
{
	t_philo	*philos;
	int		i;

	philos = malloc(sizeof(t_philo) * data->n_philos);
	if (!philos)
		return (NULL);
	i = -1;
	while (data->n_philos > ++i)
	{
		philos[i].pos = i + 1;
		philos[i].times_eaten = 0;
		philos[i].fork_l = i;
		philos[i].fork_r = i + 1;
		if (i + 1 == data->n_philos)
			philos[i].fork_r = 0;
		pthread_mutex_init(data->forks + i, NULL);
		pthread_mutex_init(&(philos[i]).check_dying_time, NULL);
		pthread_mutex_init(&(philos[i]).check_times_eaten, NULL);
		philos[i].next_dying_time = get_current_time() + data->t_die;
		philos[i].universe = data;
	}
	data->philos = philos;
	return (philos);
}

static t_universe	*start_universe(char **argv)
{
	t_universe	*data;

	data = malloc(sizeof(t_universe));
	if (!data)
		return (NULL);
	data->breaker = 1;
	data->n_fin_eating = 0;
	data->n_philos = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	data->n_eat = -1;
	if (argv[5])
		data->n_eat = ft_atoi(argv[5]);
	pthread_mutex_init(&data->check_fin_eating, NULL);
	pthread_mutex_init(&data->message, NULL);
	pthread_mutex_init(&data->check_breaker, NULL);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philos);
	if (data->forks == NULL)
		return (free(data), NULL);
	return (data);
}

static int	run_simulation(t_universe *data, t_philo *philos)
{
	int	i;

	if (data->n_philos == 1)
		return (handle_one_philo(data), 0);
	if (pthread_create(&data->death_thread, NULL, &check_death, (void *)data))
		return (1);
	pthread_detach(data->death_thread);
	i = -1;
	while (++i < data->n_philos)
	{
		if (pthread_create(&((data->philos)[i].philo_thread),
			NULL, &routines, (void *)&philos[i]))
			return (1);
	}
	i = -1;
	while (++i < data->n_philos)
	{
		if (pthread_join(((data->philos)[i].philo_thread), NULL))
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_universe	*data;
	t_philo		*philos;

	if (parsing(argc, argv))
		return (1);
	data = start_universe(argv);
	if (!data)
		return (1);
	philos = create_philos(data);
	if (!philos)
		return (free(data), 1);
	data->start_time = get_current_time();
	if (run_simulation(data, philos))
		return (1);
	free_universe(data, philos);
	return (0);
}
