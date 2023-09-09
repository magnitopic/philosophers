/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:07:46 by alaparic          #+#    #+#             */
/*   Updated: 2023/09/09 16:57:16 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	finish_simulation(t_philo *philo, int death)
{
	pthread_mutex_lock(&philo->universe->check_breaker);
	philo->universe->breaker = 0;
	pthread_mutex_unlock(&philo->universe->check_breaker);
	if (death)
		print_message(philo, DEATH);
	pthread_mutex_unlock(&philo->universe->death);
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

int	check_times_eaten(t_philo *philo)
{
	int	meals;

	pthread_mutex_lock(&philo->check_times_eaten);
	meals = philo->times_eaten;
	pthread_mutex_unlock(&philo->check_times_eaten);
	if (meals >= philo->universe->t_eat)
		return (1);
	return (0);
}

void	*check_death(void *args)
{
	int			i;
	t_universe	*data;
	t_philo		*philo;
	long		time;

	data = (t_universe *)args;
	while (check_finished(data))
	{
		i = 0;
		while (i < data->n_philos)
		{
			philo = &(data->philos)[i++];
			pthread_mutex_lock(&philo->check_dying_time);
			time = philo->next_dying_time;
			pthread_mutex_unlock(&philo->check_dying_time);
			if (get_current_time() > time)
				return (finish_simulation(philo, 1), NULL);
		}
		ft_usleep(1);
	}
	return (0);
}