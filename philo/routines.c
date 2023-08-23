/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:01:22 by alaparic          #+#    #+#             */
/*   Updated: 2023/08/23 18:57:31 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	t_universe	*universe;

	universe = philo->universe;
	pthread_mutex_lock(&universe->forks[philo->fork_l]);
	print_message(philo, FORK);
	pthread_mutex_lock(&universe->forks[philo->fork_r]);
	print_message(philo, FORK);
	print_message(philo, EAT);
	usleep(philo->universe->t_eat * 1000);
	philo->life_expectancy = get_current_time() + philo->universe->t_die;
	philo->times_eaten++;
	pthread_mutex_unlock(&universe->forks[philo->fork_l]);
	pthread_mutex_unlock(&universe->forks[philo->fork_r]);
}

void	ft_sleep(t_philo *philo)
{
	print_message(philo, SLEEP);
	usleep(philo->universe->t_sleep * 1000);
}

void	ft_think(t_philo *philo)
{
	print_message(philo, THINK);
}

void	*routines(void *args)
{
	t_philo		*philo;
	t_universe	*universe;

	philo = args;
	universe = philo->universe;
	if (philo->pos % 2 == 0)
		usleep(50 * universe->n_philos);
	while (universe->breaker
		&& (philo->times_eaten < universe->n_eat || universe->n_eat == -1))
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (0);
}
