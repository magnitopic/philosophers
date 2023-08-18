/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:18:16 by alaparic          #+#    #+#             */
/*   Updated: 2023/08/18 14:23:11 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(t_philo *philo, enum e_mssg mssg)
{
	int	time;

	time = get_cur_time();
	if (mssg == FORK)
		printf("%d %d \033[0;36has taken a fork\033[0m 🍴\n", time, philo->pos);
	if (mssg == EAT)
		printf("%d %d \033[0;33is eating\033[0m 🍝\n", time, philo->pos);
	if (mssg == SLEEP)
		printf("%d %d \033[0;34is sleeping\033[0m 💤\n", time, philo->pos);
	if (mssg == THINK)
		printf("%d %d \033[0;32is thinking\033[0m 💭\n", time, philo->pos);
	if (mssg == DIE)
		printf("%d %d \033[0;31mdied\033[0m\n", time, philo->pos);
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
