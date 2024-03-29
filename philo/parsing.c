/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:24:31 by alaparic          #+#    #+#             */
/*   Updated: 2023/09/14 11:13:58 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(char *c)
{
	int	i;

	i = 0;
	if (*(c + 1) == 0 && *c == '0')
		return (0);
	while (c[i])
	{
		if ((c[i] < '0' || c[i] > '9') && c[i] != '+')
			return (0);
		i++;
	}
	if (i > 9)
		return (0);
	return (1);
}

static int	error_message(int n)
{
	if (n == 1)
	{
		printf("\033[0;31mNumber of arguments must be between 4 and 5:\n");
		printf("\t\033[0;36m1. Number of philosophers\n");
		printf("\t2. Time to die\n");
		printf("\t3. Time to eat\n");
		printf("\t4. Time to sleep\n");
		printf("\t5. (Optional) Number of times philos must eat\033[0m");
	}
	if (n == 2)
		printf("\033[0;31mInvalid value for philosophers.\033[0m");
	if (n == 3)
		printf("\033[0;31mInvalid value for time.\033[0m");
	if (n == 4)
		printf("\033[0;31mInvalid value for times to eat.\033[0m");
	printf("\n\033[0m");
	return (1);
}

static int	check_empty(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (!(argv[i][0]))
			return (1);
	}
	return (0);
}

int	parsing(int argc, char **argv)
{
	if (argc < 5 || argc > 6 || check_empty(argc, argv))
		return (error_message(1));
	if (!ft_isdigit(argv[1]))
		return (error_message(2));
	if (!ft_isdigit(argv[2]) || !ft_isdigit(argv[3]) || !ft_isdigit(argv[4]))
		return (error_message(3));
	if (argv[5] && !ft_isdigit(argv[5]))
		return (error_message(4));
	return (0);
}
