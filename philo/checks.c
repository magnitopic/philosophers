/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:07:46 by alaparic          #+#    #+#             */
/*   Updated: 2023/09/22 08:01:06 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	finish_simulation(t_philo *philo)
{
	long	time;

	time = get_current_time() - philo->universe->start_time;
	pthread_mutex_lock(&philo->universe->check_breaker);
	philo->universe->breaker = 0;
	pthread_mutex_unlock(&philo->universe->check_breaker);
	ft_usleep(1);
	pthread_mutex_lock(&philo->universe->message);
	printf(COMMON, time, philo->pos);
	printf(DIE_MESSAGE);
	pthread_mutex_unlock(&philo->universe->message);
}

int	check_finished(t_universe *data)
{
	int	breaker;

	pthread_mutex_lock(&data->check_breaker);
	pthread_mutex_lock(&data->check_fin_eating);
	breaker = data->breaker;
	if (breaker && data->n_fin_eating == data->n_philos)
		breaker = 0;
	pthread_mutex_unlock(&data->check_fin_eating);
	pthread_mutex_unlock(&data->check_breaker);
	if (breaker)
		return (0);
	return (1);
}

void	check_finished_eating(t_universe *data, t_philo *philo)
{
	pthread_mutex_lock(&philo->check_times_eaten);
	philo->times_eaten++;
	pthread_mutex_unlock(&philo->check_times_eaten);
	if (data->n_eat != -1 && philo->times_eaten == data->n_eat)
	{
		pthread_mutex_lock(&data->check_fin_eating);
		data->n_fin_eating++;
		pthread_mutex_unlock(&data->check_fin_eating);
	}
}

void	*check_death(void *args)
{
	int			i;
	long		time;
	t_universe	*data;
	t_philo		*philo;

	data = (t_universe *)args;
	while (!check_finished(data))
	{
		i = 0;
		while (i < data->n_philos)
		{
			philo = &(data->philos)[i++];
			pthread_mutex_lock(&philo->check_dying_time);
			time = philo->next_dying_time;
			pthread_mutex_unlock(&philo->check_dying_time);
			if (get_current_time() > time)
				return (finish_simulation(philo), NULL);
		}
		ft_usleep(1);
	}
	return (NULL);
}
