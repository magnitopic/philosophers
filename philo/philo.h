/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:06:26 by alaparic          #+#    #+#             */
/*   Updated: 2023/05/18 17:46:09 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				pos;
	int				times_eaten;
	pthread_mutex_t	fork_l;
	pthread_mutex_t	*fork_r;
	t_data			*data;
}	t_philo;

typedef struct s_data
{
	int				n_philos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_eat;
	int				start_time;
	t_philo			*philos;
	pthread_mutex_t	message;
}	t_data;

int		raise_error(char *message);
int		ft_atoi(const char *str);
int		error_check(int argc, char **argv);
int		ft_isdigit(char *c);

#endif