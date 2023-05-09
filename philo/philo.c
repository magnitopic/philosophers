/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:06:33 by alaparic          #+#    #+#             */
/*   Updated: 2023/05/09 17:33:14 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	(void)argv;
	if (argc < 5 || argc > 6)
		return (raise_error("Invalid number of parameters"));
	return (0);
}
