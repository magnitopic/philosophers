/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:18:16 by alaparic          #+#    #+#             */
/*   Updated: 2023/09/22 07:59:31 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_current_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	print_message(t_philo *philo, enum e_mssg mssg, long time)
{
	if (check_finished(philo->universe))
		return ;
	pthread_mutex_lock(&philo->universe->message);
	printf(COMMON, time, philo->pos);
	if (mssg == FORK)
		printf(FORK_MESSAGE);
	else if (mssg == EAT)
		printf(EAT_MESSAGE);
	else if (mssg == SLEEP)
		printf(SLEEP_MESSAGE);
	else if (mssg == THINK)
		printf(THINK_MESSAGE);
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
	if (num > LONG_MAX && sign == 1)
		return (-1);
	else if (num > LONG_MAX && sign == -1)
		return (0); 
	return (sign * num);
}

void	ft_usleep(int time)
{
	long	start_time;

	start_time = get_current_time();
	while (get_current_time() - start_time < time)
		usleep(500);
	return ;
}

void	free_universe(t_universe *data, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < data->n_philos)
	{
		pthread_mutex_destroy(&data->forks[i++]);
		pthread_mutex_destroy(&data->philos->check_dying_time);
	}
	pthread_mutex_destroy(&data->message);
	pthread_mutex_destroy(&data->check_breaker);
	pthread_mutex_destroy(&data->check_breaker);
	free(data->forks);
	free(data);
	free(philos);
}
