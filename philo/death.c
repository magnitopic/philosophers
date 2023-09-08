/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:24:33 by alaparic          #+#    #+#             */
/*   Updated: 2023/09/08 12:08:31 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// TODO: Find more appropriate place for this function
void	handle_one_philo(t_universe *data)
{
	print_message(&data->philos[0], FORK);
	ft_usleep(data->t_die);
	printf(COMMON, data->t_die, data->philos[0].pos);
	printf(DIE_MESSAGE);
}
