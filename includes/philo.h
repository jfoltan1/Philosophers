/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:12:45 by jfoltan           #+#    #+#             */
/*   Updated: 2024/06/30 17:16:27 by jfoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/time.h>
#include <limits.h>

typedef pthread_mutex_t	t_mutex;
typedef struct s_table	t_table;
typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	FIRST_FORK,
	SECOND_FORK,
	DEDLOL,
}	t_philo_status;

typedef enum e_action
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}	t_action;

typedef enum time_code
{
	SECONDS,
	MILISECONDS,
	MICROSECONDS,
}	t_time_code;

typedef struct s_fork
{
	t_mutex		fork;
	int			fork_id;
}			t_fork;
typedef struct s_philo
{
	int			id;
	long		meals_counter;
	bool		is_full;
	long		last_meal_time;
	t_fork		*first_fork;
	t_fork		*second_fork;
	pthread_t	thread_id;
	t_table		*table;
	t_mutex		philo_mutex; 
}	t_philo;

typedef struct s_table
{
	long		num_of_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			meals_limit;
	long		start_time;
	long		nbr_of_threads_running;
	bool		end_of_simulation;
	bool		ready_for_anubis;
	bool		its_go_time;
	pthread_t	anubis;
	t_mutex		table_mutex;
	t_mutex		write_mutex;
	t_philo		*philos;
	t_fork		*forks;
}	t_table;

//utils.c
int		args_check(int argc);
void	exit_error(char *str);
long	gettime(t_time_code time_code);
void	my_usleep(long usec, t_table *table);
//parsing.c
void	parse_input(t_table *table, char **argv);
//utils_ft.c
void	*my_calloc(size_t bytes);
long	my_atol(const char *str);
//safe_handling.c
void	safe_thread_handle(pthread_t *thread, void *(*foo)(void *),
			t_action action, void *data);
void	safe_mutex_handle(t_mutex *mutex, t_action action);
//set_the_table.c
void	set_the_table(t_table *table);
//clean_func.c
void	set_bool(t_mutex *mutex, bool *dest, bool value);
bool	get_bool(t_mutex *mutex, bool *value);
long	get_long(t_mutex *mutex, long *value);
void	set_long(t_mutex *mutex, long *dest, long value);
bool	simulation_finish(t_table *table);
//synchro.c
void	godricks_hat(t_philo *philo);
void	wait_on_threads(t_table *table);
bool	all_threads_ready(t_mutex *mutex, long *threads, long philo_nbr);
void	increase_long(t_mutex *mutex, long *value);
//write_status.c
void	write_status(t_philo_status status, t_philo *philo);
//dinner.c
void	philosophise(t_table *table);
void	think(t_philo *philo, bool before_simulation);
//monitor.c
void	*hello_darkness(void *data);