/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:01:22 by alaparic          #+#    #+#             */
/*   Updated: 2023/08/30 15:36:54 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_eat(t_philo *philo)
{
	t_universe	*universe;

	universe = philo->universe;
	pthread_mutex_lock(&universe->forks[philo->fork_l]);
	print_message(philo, FORK);
	pthread_mutex_lock(&universe->forks[philo->fork_r]);
	print_message(philo, FORK);
	philo->next_dying_time = get_current_time() + philo->universe->t_die;
	pthread_mutex_lock(&philo->eating);
	print_message(philo, EAT);
	pthread_mutex_unlock(&philo->eating);
	usleep(philo->universe->t_eat * 1000);
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

	philo = (t_philo *)args;
	universe = philo->universe;
	if (philo->pos % 2 == 0)
		usleep(30000);
	while (universe->breaker)
	{
		ft_eat(philo);
		if (philo->times_eaten == universe->n_eat)
			break ;
		ft_sleep(philo);
		if (philo->times_eaten == universe->n_eat)
			break ;
		ft_think(philo);
		if (philo->times_eaten == universe->n_eat)
			break ;
	}
	return (0);
}
