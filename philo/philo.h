/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:06:26 by alaparic          #+#    #+#             */
/*   Updated: 2023/08/21 13:20:20 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

/* Enum */

enum e_mssg
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIE
};

/* Structs */

typedef struct s_philo
{
	int				pos;
	int				times_eaten;
	pthread_mutex_t	fork_l;
	pthread_mutex_t	*fork_r;
}	t_philo;

/**
 * - breaker: flag for when the program ends
*/
typedef struct s_universe
{
	int				n_philos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_eat;
	int				start_time;
	int				breaker;
	t_philo			*philos;
	pthread_mutex_t	*message;
}	t_universe;

/* Functions */

int		parsing(int argc, char **argv);
int		raise_error(char *message);
int		ft_atoi(const char *str);
void	print_message(t_philo *philo, enum e_mssg mssg);

#endif
