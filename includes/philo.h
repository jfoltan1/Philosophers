#ifndef PHILO_H
# define PHILO_H

# include "../libft/libft.h"
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef enum e_state
{
	eating,
	sleeping,
	thinking,

} t_state;

typedef struct s_philo
{
	int id;
	pthread_t philo_thread;
	int time_of_last_meal;
	int num_of_meals;
	t_state state;
	pthread_mutex_t *fork;
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
//PHILOS_INIT
pthread_t	create_thread(void);
void init_philos(t_data	*data);
//ROUTINE
void *routine(void *data);
//EVEN
void	even_start(t_data *data);
// UTILS
int	check_args(int argc, char **argv);
int	get_time_to_die(char **argv);
char *state_to_string(t_state state);
// UTILS_FT
char	*ft_itoa(int n);
void   ft_putstr_fd(char *s, int fd);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
int	ft_atoi(const char *nptr);
#endif