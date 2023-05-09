/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:06:26 by alaparic          #+#    #+#             */
/*   Updated: 2023/05/09 17:20:14 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_philo
{
	int				num;
	pthread_t		thread;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	fork_l;
}	t_philo;

typedef struct s_data
{
	int		n_philo;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		n_eat;
	t_philo	*philos;
}	t_data;

int		raise_error(char *message);
int		ft_atoi(const char *str);

#endif