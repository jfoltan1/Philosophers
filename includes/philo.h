#ifndef PHILO_H
# define PHILO_H

# include "../libft/libft.h"
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdbool.h>

typedef enum e_time_code
{
	SECONDS,
	MILLISECOND,
	MICROSECOND,
}		t_time_code;

/*
		*1 is fork
		*2 is dead
		*3 is eating
		*4 is sleeping
		*5 is thinking
	*/

typedef struct s_philo
{
	pthread_t philo_thread;
	int num_of_philos;
	int id;
	unsigned int time_to_die;
	int time_to_eat;
	int time_to_think;
	int time_to_sleep;
	size_t time_on_start;
	int num_of_times_each_philo_must_eat;
	size_t time_of_last_meal;
	int num_of_meals;
	int state;
	pthread_mutex_t *l_fork;
	pthread_mutex_t *r_fork;
	bool *running;
}				t_philo;


typedef struct s_data
{
	bool running;
	pthread_t anubis;
	int index_cause_im_a_fool;
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

// UTILS
int	check_args(int argc, char **argv);
long	gettime(int time_code);
int	get_time_to_die(char **argv);
// UTILS_FT
int	ft_strcmp(const char *s1, const char *s2);
char	*ft_itoa(int n);
void   ft_putstr_fd(char *s, int fd);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
int	ft_atoi(const char *nptr);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
#endif