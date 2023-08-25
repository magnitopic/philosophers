/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:01:22 by alaparic          #+#    #+#             */
/*   Updated: 2023/08/25 14:40:53 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_eat(t_philo *philo)
{
	t_universe	*universe;

	universe = philo->universe;
	pthread_mutex_lock(&universe->forks[philo->fork_r]);
	print_message(philo, FORK);
	pthread_mutex_lock(&universe->forks[philo->fork_l]);
	print_message(philo, FORK);
	print_message(philo, EAT);
	usleep(philo->universe->t_eat * 1000);
	philo->life_expectancy = get_current_time() + philo->universe->t_die;
	philo->times_eaten++;
	pthread_mutex_unlock(&universe->forks[philo->fork_l]);
	pthread_mutex_unlock(&universe->forks[philo->fork_r]);
}

static void	ft_sleep(t_philo *philo)
{
	print_message(philo, SLEEP);
	usleep(philo->universe->t_sleep * 1000);
}

static void	ft_think(t_philo *philo)
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
	while (universe->breaker)
	{
		ft_eat(philo);
		if (philo->times_eaten == universe->n_eat)
			break ;
		ft_sleep(philo);
		ft_think(philo);
	}
	return (0);
}
