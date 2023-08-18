/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:01:22 by alaparic          #+#    #+#             */
/*   Updated: 2023/08/18 13:17:36 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	ft_eat(t_philo *philo)
{
	print_message(philo, FORK);
	print_message(philo, FORK);
	print_message(philo, EAT);
}

void	ft_sleep(t_philo *philo)
{
	print_message(philo, SLEEP);
}

void	ft_think(t_philo *philo)
{
	print_message(philo, THINK);
}
