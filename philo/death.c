/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:24:33 by alaparic          #+#    #+#             */
/*   Updated: 2023/09/05 18:22:07 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	handle_death(t_philo *philo, t_universe *data)
{
	int			time;

	time = get_current_time() - philo->universe->start_time;
	pthread_mutex_lock(&data->check_breaker);
	data->breaker = 0;
	pthread_mutex_unlock(&data->check_breaker);
	usleep(1000);
	pthread_mutex_lock(&data->message);
	printf(COMMON, time, philo->pos);
	printf(DIE_MESSAGE);
	pthread_mutex_unlock(&data->message);
}

void	*check_death(void *args)
{
	int			i;
	t_universe	*data;
	t_philo		*philo;
	int			time;

	data = (t_universe *)args;
	usleep(500);
	while (data->breaker)
	{
		i = 0;
		while (i < data->n_philos)
		{
			philo = &(data->philos)[i++];
			pthread_mutex_lock(&philo->check_dying_time);
			time = philo->next_dying_time;
			pthread_mutex_unlock(&philo->check_dying_time);
			if (get_current_time() >= time)
			{
				printf("HA PALMAO EN: %d\n", get_current_time() - time);
				handle_death(philo, data);
				return (0);
			}
		}
	}
	return (0);
}
