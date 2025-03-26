/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:37:07 by jfoltan           #+#    #+#             */
/*   Updated: 2024/06/30 17:48:21 by jfoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	void	eat(t_philo *philo)
{
	safe_mutex_handle(&philo->first_fork->fork, LOCK);
	write_status(FIRST_FORK, philo);
	safe_mutex_handle(&philo->second_fork->fork, LOCK);
	write_status(SECOND_FORK, philo);
	set_long(&philo->philo_mutex, &philo->last_meal_time, gettime(MILISECONDS));
	philo->meals_counter++;
	write_status(EATING, philo);
	my_usleep(philo->table->time_to_eat, philo->table);
	if (philo->table->meals_limit > 0
		&& philo->meals_counter == philo->table->meals_limit)
		set_bool(&philo->philo_mutex, &philo->is_full, true);
	safe_mutex_handle(&philo->first_fork->fork, UNLOCK);
	safe_mutex_handle(&philo->second_fork->fork, UNLOCK);
}

void	think(t_philo *philo, bool before_simulation)
{
	long	t_eat;
	long	t_sleep;
	long	t_think;

	if (!before_simulation)
		write_status(THINKING, philo);
	if (philo->table->num_of_philos % 2 == 0)
		return ;
	t_eat = philo->table->time_to_eat;
	t_sleep = philo->table->time_to_sleep;
	t_think = (t_eat * 2) - t_sleep;
	if (t_think < 0)
		t_think = 0;
	my_usleep(t_think * 0.42, philo->table);
}

void	*dinner_simulation(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_on_threads(philo->table);
	set_long(&philo->philo_mutex, &philo->last_meal_time, gettime(MILISECONDS));
	increase_long(&philo->table->table_mutex,
		&philo->table->nbr_of_threads_running);
	godricks_hat(philo);
	while (!simulation_finish(philo->table))
	{
		if (get_bool(&philo->philo_mutex, &philo->is_full))
			break ;
		eat(philo);
		write_status(SLEEPING, philo);
		my_usleep(philo->table->time_to_sleep, philo->table);
		think(philo, false);
	}
	return (NULL);
}

static void	*darwinism(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_on_threads(philo->table);
	set_long(&philo->table->table_mutex, &philo->last_meal_time,
		gettime(MILISECONDS));
	increase_long(&philo->table->table_mutex,
		&philo->table->nbr_of_threads_running);
	set_bool(&philo->table->table_mutex, &philo->table->ready_for_anubis, true);
	write_status(FIRST_FORK, philo);
	while (!simulation_finish(philo->table))
		usleep(200);
	return (NULL);
}

void	philosophise(t_table *table)
{
	int	i;

	i = -1;
	if (table->meals_limit == 0)
		return ;
	else if (table->num_of_philos == 1)
		safe_thread_handle(&table->philos[0].thread_id, darwinism, CREATE,
			&table->philos[0]);
	else
		while (++i < table->num_of_philos)
			safe_thread_handle(&table->philos[i].thread_id,
				dinner_simulation, CREATE, &table->philos[i]);
	safe_thread_handle(&table->anubis, hello_darkness, CREATE, table);
	table->start_time = gettime(MILISECONDS);
	set_bool(&table->table_mutex, &table->its_go_time, true);
	i = -1;
	while (++i < table->num_of_philos)
		safe_thread_handle(&table->philos[i].thread_id, NULL, JOIN, NULL);
	set_bool(&table->table_mutex, &table->end_of_simulation, true);
	safe_thread_handle(&table->anubis, NULL, JOIN, NULL);
}
