/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:01:22 by alaparic          #+#    #+#             */
/*   Updated: 2023/08/22 16:46:18 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	print_message(philo, FORK);
	print_message(philo, FORK);
	print_message(philo, EAT);
	usleep(philo->universe->t_eat * 1000);
	philo->life_expectancy = get_current_time() + philo->universe->t_die;
	philo->times_eaten++;
}

void	ft_sleep(t_philo *philo)
{
	print_message(philo, SLEEP);
	usleep(philo->universe->t_sleep + 1000);
}

void	ft_think(t_philo *philo)
{
	print_message(philo, THINK);
}

/* void	*routines(void *coso)
{
	struct t_universe	*aux;

	aux = (struct t_universe *)coso;
	ft_eat();
	ft_sleep();
	ft_think();
	return (NULL);
} */
