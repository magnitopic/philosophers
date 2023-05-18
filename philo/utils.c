/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:18:16 by alaparic          #+#    #+#             */
/*   Updated: 2023/05/18 17:52:44 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	raise_error(char *message)
{
	printf("\033[0;31mError\n%s\n\033[0m", message);
	return (-1);
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

int	ft_isdigit(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (c[i] < '0' || c[i] > '9')
			return (0);
		i++;
	}
	if (i > 10)
		return (0);
	return (1);
}

void	print_action(t_philo philo, long timestamp, int opt)
{
	pthread_mutex_lock(&philo->table->message);
	printf("%d %d ", timestamp, philo_n);
	if (opt == 1)
		printf("has taken a fork\n");
	else if (opt == 2)
		printf("is eating\n");
	else if (opt == 3)
		printf("is sleeping\n");
	else if (opt == 4)
		printf("is thinking\n");
	pthread_mutex_unlock(&philo->table->message);
}
