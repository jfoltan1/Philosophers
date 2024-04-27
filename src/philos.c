/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:07:15 by jfoltan           #+#    #+#             */
/*   Updated: 2024/04/27 18:15:26 by jfoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void init_forks(t_data *data, int i)
{
	data->philo[i]->r_fork = (pthread_mutex_t *)ft_calloc(1, sizeof(pthread_mutex_t));
	pthread_mutex_init(data->philo[i]->r_fork, NULL);
	if (i == 1)
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
void put_message(int state,t_philo *philo)
{
	/*
		*1 is fork
		*2 is dead
		*3 is eating
		*4 is sleeping
		*5 is thinking
	*/
	// increment number of meals
	if (state == 1)
	{
		printf("%zu %d has taken a fork\n", get_time() - philo->time_on_start, philo->id);
	}
	if (state == 2)
	{
		philo->state = 2;
		printf("%zu %d died\n", get_time() - philo->time_on_start, philo->id);
		return;
	}
	if (state == 3)
	{
		philo->state = 3;
		printf("%zu %d is eating\n", get_time() - philo->time_on_start, philo->id);
		usleep(philo->time_to_eat * 1000);
		philo->time_of_last_meal = get_time() - philo->time_on_start;
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
	}
	if (state == 4)
		{
			philo->state = 4;
			printf("%zu %d is sleeping\n", get_time() - philo->time_on_start, philo->id);
			usleep(philo->time_to_sleep * 1000);
		}
	if (state == 5)
	{
		philo->state = 5;
		printf("%zu %d is thinking\n", get_time() - philo->time_on_start, philo->id);
		usleep(1000);
	}
	fflush(stdout);
}
void routine(t_philo *philo)
{
	while (1)
	{
		fflush(stdout);
		pthread_mutex_lock(philo->r_fork);
		put_message(1, philo);
		pthread_mutex_lock(philo->l_fork);
		put_message(1, philo);
		put_message(3, philo);
		put_message(4, philo);
		put_message(5, philo);
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
				put_message(4, philo);
				usleep(philo->time_to_sleep * 1000);
				routine(philo);
			}
	}
	else 
	{
		if (philo->id % 2 != 0)
		{
			put_message(5, philo);
			usleep(philo->time_to_sleep * 1000);
		}
		routine(philo);
	}
}
void hello_darkness(void *data_ptr)
{
	t_data *data;
	t_philo **philo_arr;
	int i;
	int num_of_philos;
	i = 0;

	data = (t_data *)data_ptr;
	philo_arr = data->philo;
	num_of_philos = philo_arr[1]->num_of_philos;
	while (++i < num_of_philos)
	{
		if ((get_time() - philo_arr[i]->time_on_start - philo_arr[i]->time_of_last_meal) > philo_arr[i]->time_to_die)
		{
			put_message(2, philo_arr[i]);
			break;
		}
		if (i == num_of_philos)
			i = 0;
	}
}
void philosophise(t_data *data)
{
	int i;

	i = 0;
	while (++i <= data->philo[1]->num_of_philos)
		pthread_create(&data->philo[i]->philo_thread, NULL, (void *)(godricks_hat), (void *)data->philo[i]);
	pthread_create(&data->anubis, NULL, (void *)(hello_darkness), (void *)data);
}
void init_philos(char **argv, t_data	*data)
{
	int i;
	int num_of_philos;
	num_of_philos = ft_atoi(argv[1]);

	i = 0;
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
		data->philo[i]->state = 5;
		init_forks(data, i);
		data->philo[i]->dead_lock = &data->dead_lock;
		data->philo[i]->meal_lock = &data->meal_lock;
		data->philo[i]->write_lock = &data->write_lock;
	}
	data->philo[1]->l_fork = data->philo[ft_atoi(argv[1]) - 1]->r_fork;
	pthread_mutex_init(data->philo[1]->l_fork, NULL);
	philosophise(data);
}
