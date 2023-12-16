#ifndef PHILO_H
# define PHILO_H

# include "../libft/libft.h"
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo
{
	int id;
	pthread_t philo_thread;
	int time_of_last_meal;
	int num_of_meals;
}				t_philo;

typedef struct s_data
{
	struct timeval time;
	int time_on_start;
	int num_of_philos;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int num_of_times_each_philo_must_eat;
	t_philo **philo;
}				t_data;

//MAIN
t_data 	*init_data(char **argv,struct timeval time);
//PHILOS
pthread_t	create_thread(void);
void init_philos(t_data	*data);
// UTILS
int	check_args(int argc, char **argv);
int	get_time_to_die(char **argv);
// UTILS_FT

void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
int	ft_atoi(const char *nptr);
#endif