/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:01:22 by alaparic          #+#    #+#             */
/*   Updated: 2023/09/13 09:21:43 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_eat(t_philo *philo)
{
	t_universe	*universe;
	long		time;

	universe = philo->universe;
	pthread_mutex_lock(&universe->forks[philo->fork_l]);
	time = get_current_time() - universe->start_time;
	print_message(philo, FORK, time);
	pthread_mutex_lock(&universe->forks[philo->fork_r]);
	time = get_current_time() - universe->start_time;
	print_message(philo, FORK, time);
	pthread_mutex_lock(&philo->check_dying_time);
	philo->next_dying_time = get_current_time() + philo->universe->t_die;
	pthread_mutex_unlock(&philo->check_dying_time);
	time = get_current_time() - universe->start_time;
	print_message(philo, EAT, time);
	ft_usleep(philo->universe->t_eat);
	pthread_mutex_unlock(&philo->universe->forks[philo->fork_l]);
	pthread_mutex_unlock(&philo->universe->forks[philo->fork_r]);
	pthread_mutex_lock(&philo->check_times_eaten);
	philo->times_eaten++;
	pthread_mutex_unlock(&philo->check_times_eaten);
}

static void	ft_sleep(t_philo *philo)
{
	long	time;

	time = get_current_time() - philo->universe->start_time;
	print_message(philo, SLEEP, time);
	ft_usleep(philo->universe->t_sleep);
}

static void	ft_think(t_philo *philo)
{
	long	time;

	time = get_current_time() - philo->universe->start_time;
	print_message(philo, THINK, time);
}

void	*routines(void *args)
{
	t_philo		*philo;
	t_universe	*universe;

	philo = (t_philo *)args;
	universe = philo->universe;
	if (philo->pos % 2 == 0)
		ft_usleep(30);
	while (!check_finished(universe))
	{
		ft_eat(philo);
		if (philo->times_eaten == universe->n_eat)
			break ;
		ft_sleep(philo);
		ft_think(philo);
	}
	return (0);
}
