/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:07:46 by alaparic          #+#    #+#             */
/*   Updated: 2023/09/08 10:55:42 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	check_death(t_philo *philo)
{
	int	eating;
	long	
}
