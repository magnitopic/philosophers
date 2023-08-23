/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:06:26 by alaparic          #+#    #+#             */
/*   Updated: 2023/08/23 12:30:28 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
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
	int					pos;
	int					times_eaten;
	int					fork_l;
	int					fork_r;
	int					life_expectancy;
	pthread_t			filo_thread;
	struct s_universe	*universe;
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
	int				breaker;
	int				start_time;
	pthread_mutex_t	message;
	pthread_mutex_t	death;
	t_philo			*philos;
	pthread_mutex_t	*forks;
}	t_universe;

/* Functions */

int		parsing(int argc, char **argv);
int		raise_error(char *message);
int		ft_atoi(const char *str);
void	*routines(void *args);
void	print_message(t_philo *philo, enum e_mssg mssg);
int		get_current_time(void);
void	free_universe(t_universe *data, t_philo *philos);

#endif
