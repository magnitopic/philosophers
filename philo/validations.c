/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:07:46 by alaparic          #+#    #+#             */
/*   Updated: 2023/09/13 09:22:12 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	finish_simulation(t_philo *philo, int death)
{
	long	time;

	time = get_current_time() - philo->universe->start_time;
	pthread_mutex_lock(&philo->universe->check_breaker);
	philo->universe->breaker = 0;
	pthread_mutex_unlock(&philo->universe->check_breaker);
	if (death)
	{
		ft_usleep(1);
		pthread_mutex_lock(&philo->universe->message);
		printf(COMMON, time, philo->pos);
		printf(DIE_MESSAGE);
		pthread_mutex_unlock(&philo->universe->message);
	}
}

int	check_finished(t_universe *data)
{
	int	breaker;

	pthread_mutex_lock(&data->check_breaker);
	breaker = data->breaker;
	pthread_mutex_unlock(&data->check_breaker);
	if (breaker)
		return (0);
	return (1);
}

void	*check_death(void *args)
{
	int			i;
	long		time;
	t_universe	*data;
	t_philo		*philo;
	int			eaten;

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
			if ((get_current_time() > time && data->n_eat == -1))
			{
				printf("Died from time\n");
				return (finish_simulation(philo, 1), NULL);
			}
			pthread_mutex_lock(&philo->check_times_eaten);
			eaten = philo->times_eaten;
			pthread_mutex_unlock(&philo->check_times_eaten);
			if (get_current_time() > time && eaten >= data->t_eat)
			{
				printf("Died times eaten\n");
				return (finish_simulation(philo, 1), NULL);
			}
		}
		ft_usleep(1);
	}
	return (0);
}
