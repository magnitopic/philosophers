/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:24:31 by alaparic          #+#    #+#             */
/*   Updated: 2023/05/10 17:07:21 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	error_message(int n)
{
	if (n == 1)
	{
		printf("\033[0;31mNumber of arguments must be between 4 and 5:\n");
		printf("\t\033[0;36m1. Number of philosophers\n");
		printf("\t2. Time to die\n");
		printf("\t3. Time to eat\n");
		printf("\t4. Time to sleep\n");
		printf("\t5. (Optional) Number of times philos must eat\033[0m\n");
	}
	return (1);
}

int	error_check(int argc, char **argv)
{
	(void)argv;
	if (argc < 5 || argc > 6)
		return (error_message(1));
	return (0);
}
