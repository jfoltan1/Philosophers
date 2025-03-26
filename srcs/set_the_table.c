/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_the_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:57:59 by jfoltan           #+#    #+#             */
/*   Updated: 2024/06/30 17:47:01 by jfoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	assign_forks(t_philo *philo, t_fork *forks, int i)
{
	philo->first_fork = &forks[(i + 1) % philo->table->num_of_philos];
	philo->second_fork = &forks[i];
	if (i % 2 == 0)
	{
		philo->first_fork = &forks[i];
		philo->second_fork = &forks[(i + 1) % philo->table->num_of_philos];
	}
}

static void	philo_init(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < table->num_of_philos)
	{
		philo = table->philos + i;
		philo->id = i + 1;
		philo->meals_counter = 0;
		philo->is_full = false;
		philo->table = table;
		assign_forks(philo, table->forks, i);
		safe_mutex_handle(&philo->philo_mutex, INIT);
	}
}

void	set_the_table(t_table *table)
{
	int	i;

	i = -1;
	table->nbr_of_threads_running = 0;
	table->ready_for_anubis = false;
	table->its_go_time = false;
	table->end_of_simulation = false;
	table->philos = my_calloc(sizeof(t_philo) * table->num_of_philos);
	table->forks = my_calloc(sizeof(t_fork) * table->num_of_philos);
	safe_mutex_handle(&table->table_mutex, INIT);
	safe_mutex_handle(&table->write_mutex, INIT);
	while (++i < table->num_of_philos)
	{
		safe_mutex_handle(&table->forks[i].fork, INIT);
		table->forks[i].fork_id = i;
	}
	philo_init(table);
}
