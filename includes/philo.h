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
	pthread_t philo_thread;
	int num_of_philos;
	int id;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	size_t time_on_start;
	int num_of_times_each_philo_must_eat;
	int time_of_last_meal;
	int num_of_meals;
	t_state state;
	int *dead;
	pthread_mutex_t *l_fork;
	pthread_mutex_t *r_fork;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
	pthread_mutex_t	*write_lock;
}				t_philo;

typedef struct s_data
{
	int dead;
	size_t start_time;	
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo **philo;
}				t_data;

//MAIN
t_data 	*init_data(char **argv);
//PHILOS_INIT
pthread_t	create_thread(void);
void init_philos(char **argv, t_data	*data);
//ROUTINE
void routine(void *data);
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