/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:06:26 by alaparic          #+#    #+#             */
/*   Updated: 2023/09/05 19:29:08 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

/* Messages to print */

# define COMMON "\033[1;30m%d ms\t\033[1;31m%d"
# define FORK_MESSAGE "\033[0;36m has taken a fork\033[0m 🍴\n"
# define EAT_MESSAGE "\033[0;33m is eating\033[0m 🍝\n"
# define SLEEP_MESSAGE "\033[0;34m is sleeping\033[0m 💤\n"
# define THINK_MESSAGE "\033[0;32m is thinking\033[0m 💭\n"
# define DIE_MESSAGE "\033[0;31m died 💀\033[0m\n"

/* Enum */

enum e_mssg
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DEATH
};

/* Structs */

typedef struct s_philo
{
	int					pos;
	int					times_eaten;
	int					fork_l;
	int					fork_r;
	int					next_dying_time;
	pthread_mutex_t		check_dying_time;
	pthread_t			philo_thread;
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
	int				start_time;
	int				breaker;
	pthread_mutex_t	check_breaker;
	pthread_mutex_t	message;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_t		death_thread;
}	t_universe;

/* Functions */

void	*routines(void *args);
int		get_current_time(void);
int		ft_atoi(const char *str);
void	*check_death(void *args);
int		raise_error(char *message);
int		parsing(int argc, char **argv);
void	handle_one_philo(t_universe *data);
void	print_message(t_philo *philo, enum e_mssg mssg);
void	free_universe(t_universe *data, t_philo *philos);

#endif
