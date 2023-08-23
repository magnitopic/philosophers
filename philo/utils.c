/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:18:16 by alaparic          #+#    #+#             */
/*   Updated: 2023/08/23 18:25:00 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_current_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	print_message(t_philo *philo, enum e_mssg mssg)
{
	int	time;

	pthread_mutex_lock(&philo->universe->message);
	time = get_current_time() - philo->universe->start_time;
	if (mssg == FORK)
		printf("%d %d\033[0;36m has taken a fork\033[0m 🍴\n", time, philo->pos);
	else if (mssg == EAT)
		printf("%d %d\033[0;33m is eating\033[0m 🍝\n", time, philo->pos);
	else if (mssg == SLEEP)
		printf("%d %d\033[0;34m is sleeping\033[0m 💤\n", time, philo->pos);
	else if (mssg == THINK)
		printf("%d %d\033[0;32m is thinking\033[0m 💭\n", time, philo->pos);
	else if (mssg == DIE)
		printf("%d %d\033[0;31m died 💀\033[0m\n", time, philo->pos);
	pthread_mutex_unlock(&philo->universe->message);
}

int	ft_atoi(const char *str)
{
	int		sign;
	size_t	num;

	sign = 1;
	num = 0;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	if (num > 9223372036854775807 && sign == 1)
		return (-1);
	else if (num > 9223372036854775807 && sign == -1)
		return (0);
	return (sign * num);
}

void	free_universe(t_universe *data, t_philo *philos)
{
	// TODO: Free forks inside data
	pthread_mutex_destroy(&data->message);
	pthread_mutex_destroy(&data->death);
	free(data);
	free(philos);
}
