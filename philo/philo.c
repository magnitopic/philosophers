/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:06:33 by alaparic          #+#    #+#             */
/*   Updated: 2023/08/29 19:22:08 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* void	*check_death(void *args)
{
	t_philo		*philo;
	t_universe	*universe;

	philo = (t_philo *)args;
	universe = philo->universe;
	while (universe->breaker)
	{
		usleep(10);
		if (get_current_time() - universe->start_time >= philo->next_dying_time)
		{
			universe->breaker = 0;
			pthread_mutex_lock(&universe->death);
			print_message(philo, DEATH);
			pthread_mutex_lock(&universe->death);
		}
	}
	return (0);
} */

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
		//printf("philo: %d Forks:\t %d - %d\n", philos[i].pos, philos[i].fork_l + 1, philos[i].fork_r + 1);
		pthread_mutex_init(data->forks + i, NULL);
		pthread_mutex_init(&(philos[i]).eating, NULL);
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
	data->n_philos = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	data->n_eat = -1;
	if (argv[5])
		data->n_eat = ft_atoi(argv[5]);
	pthread_mutex_init(&data->message, NULL);
	pthread_mutex_init(&data->death, NULL);
	data->forks = malloc((sizeof(pthread_mutex_t) * data->n_philos) + 1);
	if (data->forks == NULL)
		return (free(data), NULL);
	return (data);
}

static int	run_simulation(t_universe *data, t_philo *philos)
{
	int	i;

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

	(void)argv;
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
