/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:07:15 by jfoltan           #+#    #+#             */
/*   Updated: 2024/04/23 16:32:13 by jfoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void init_forks(t_data *data, int i)
{
	data->philo[i]->r_fork = (pthread_mutex_t *)ft_calloc(1, sizeof(pthread_mutex_t));
	pthread_mutex_init(data->philo[i]->r_fork, NULL);
	if (i == 0)
	{
		data->philo[i]->l_fork = (pthread_mutex_t *)ft_calloc(1, sizeof(pthread_mutex_t));
		pthread_mutex_init(data->philo[i]->l_fork, NULL);
	}
	else
		data->philo[i]->l_fork = data->philo[i - 1]->r_fork;
}
size_t get_time(void)
{
	struct timeval rn;
	size_t time;
	gettimeofday(&rn, NULL);
	time = (size_t) (rn.tv_sec * 1000 + rn.tv_usec / 1000);
	return time;
}
int is_odd(t_philo *philo)
{
	if (philo->num_of_philos % 2 != 0)
		return(1);
	return(0);
}
void put_message(char *state,t_philo *philo)
{
	// increment number of meals
	if (ft_strcmp(state, "sleeping"))
		{
			printf("%zu %d is %s\n", get_time() - philo->time_on_start, philo->id, state);
			philo->state = sleeping;
			usleep(philo->time_to_sleep * 1000);
		}
	if (ft_strcmp(state, "eating"))
	{
		printf("%zu %d is %s\n", get_time() - philo->time_on_start, philo->id, state);
		philo->time_of_last_meal = get_time();
		philo->state = eating;
		usleep(philo->time_to_eat * 1000);
	}
	if (ft_strcmp(state, "thinking"))
	{
		printf("%zu %d is %s\n", get_time() - philo->time_on_start, philo->id, state);
		philo->state = thinking;
		usleep(1000);
	}
	if (ft_strcmp(state, "fork"))
	{
		printf("%zu %d has taken a %s\n", get_time() - philo->time_on_start, philo->id, state);
	}
	fflush(stdout);
}
void routine(t_philo *philo)
{
	while (1)
	{
		printf("I am philo number : %d\n", philo->id);
		fflush(stdout);
		pthread_mutex_lock(philo->l_fork);
		put_message("fork", philo);
		pthread_mutex_lock(philo->r_fork);
		philo->time_of_last_meal = get_time();
		put_message("eating", philo);
		put_message("sleeping", philo);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
	}
}
void 	godricks_hat(void *philo_ptr)
{
	t_philo *philo;
	
	philo = (t_philo *)philo_ptr;
	if (is_odd(philo))
	{
		//implement later
			if (philo->id % 2 != 0)
				routine(philo);	
			else
			{
				put_message("sleeping", philo);
				usleep(philo->time_to_sleep * 1000);
				routine(philo);
			}
	
	}
	else 
	{
		if (philo->id % 2 != 0)
		{
			put_message("sleeping", philo);
			usleep(philo->time_to_sleep * 1000);
		}	
		routine(philo);
	}
}
void philosophise(t_data *data)
{
	int i;

	i = -1;
	while (++i < data->philo[0]->num_of_philos)
		pthread_create(&data->philo[i]->philo_thread, NULL, (void *)(godricks_hat), (void *)data->philo[i]);
	
}
void init_philos(char **argv, t_data	*data)
{
	int i;
	int num_of_philos;
	num_of_philos = ft_atoi(argv[1]);

	i = -1;
	while (++i <= num_of_philos)
	{
		data->philo[i] = (t_philo *)ft_calloc(1, sizeof(t_philo));
		data->philo[i]->id = i;
		data->philo[i]->num_of_philos = ft_atoi(argv[1]);
		data->philo[i]->time_to_die = get_time_to_die(argv);
		data->philo[i]->time_to_eat = ft_atoi(argv[3]);
		data->philo[i]->time_to_sleep = ft_atoi(argv[4]);
		data->philo[i]->num_of_times_each_philo_must_eat = ft_atoi(argv[5]);
		data->philo[i]->time_of_last_meal = 0;
		data->philo[i]->time_on_start = data->start_time;
		data->philo[i]->num_of_meals = 0;
		data->philo[i]->state = thinking;
		data->philo[i]->dead = &data->dead;
		init_forks(data, i);
		data->philo[i]->dead_lock = &data->dead_lock;
		data->philo[i]->meal_lock = &data->meal_lock;
		data->philo[i]->write_lock = &data->write_lock;
	}
	data->philo[0]->l_fork = data->philo[ft_atoi(argv[1]) - 1]->r_fork;
	pthread_mutex_init(data->philo[0]->l_fork, NULL);
	philosophise(data);
}
