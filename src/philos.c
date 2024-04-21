/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:07:15 by jfoltan           #+#    #+#             */
/*   Updated: 2024/04/21 19:51:03 by jfoltan          ###   ########.fr       */
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
void routine(void *philo_ptr)
{
	 t_philo *philo = (t_philo *)philo_ptr;
	printf("%ld routine\n", (get_time() - philo->time_on_start));
	fflush(stdout);
}
void philosophise(t_data *data)
{
	int i;

	i = -1;
	while (++i < data->philo[0]->num_of_philos)
		pthread_create(&data->philo[i]->philo_thread, NULL, (void *)(routine), (void *)data->philo[i]);
	
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
