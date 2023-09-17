/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:06:26 by alaparic          #+#    #+#             */
/*   Updated: 2023/09/17 16:52:00 by alaparic         ###   ########.fr       */
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

/* # define COMMON "\033[1;30m%-5ld ms \033[1;31m%d"
# define FORK_MESSAGE "\033[0;36m has taken a fork\033[0m 🍴\n"
# define EAT_MESSAGE "\033[0;33m is eating\033[0m 🍝\n"
# define SLEEP_MESSAGE "\033[0;34m is sleeping\033[0m 💤\n"
# define THINK_MESSAGE "\033[0;32m is thinking\033[0m 💭\n"
# define DIE_MESSAGE "\033[0;31m died 💀\033[0m\n" */

/* Simple version */

# define COMMON "%ld %d"
# define FORK_MESSAGE " has taken a fork\n"
# define EAT_MESSAGE " is eating\n"
# define SLEEP_MESSAGE " is sleeping\n"
# define THINK_MESSAGE " is thinking\n"
# define DIE_MESSAGE " died\n"

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
	long				next_dying_time;
	pthread_mutex_t		check_times_eaten;
	pthread_mutex_t		check_dying_time;
	pthread_t			philo_thread;
	struct s_universe	*universe;
}	t_philo;

typedef struct s_universe
{
	int				n_philos;
	long			t_die;
	long			t_eat;
	long			t_sleep;
	int				n_eat;
	long			start_time;
	int				breaker;
	int				n_fin_eating;
	pthread_mutex_t	check_breaker;
	pthread_mutex_t	check_fin_eating;
	pthread_mutex_t	message;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_t		death_thread;
}	t_universe;

/* Functions */

void	ft_usleep(int time);
void	*routines(void *args);
long	get_current_time(void);
void	*check_death(void *args);
int		ft_atoi(const char *str);
int		parsing(int argc, char **argv);
int		check_finished(t_universe *data);
void	free_universe(t_universe *data, t_philo *philos);
void	check_finished_eating(t_universe *data, t_philo *philo);
void	print_message(t_philo *philo, enum e_mssg mssg, long time);

#endif
