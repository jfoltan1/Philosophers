/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:44:13 by jfoltan           #+#    #+#             */
/*   Updated: 2024/06/30 17:48:11 by jfoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	is_ded_or_nah(t_philo *philo)
{
	long	elapsed;
	long	time_to_die;

	if (get_bool(&philo->philo_mutex, &philo->is_full))
		return (false);
	elapsed = gettime(MILISECONDS) - get_long(&philo->philo_mutex,
			&philo->last_meal_time);
	time_to_die = philo->table->time_to_die;
	if (elapsed > time_to_die / 1e3)
		return (true);
	return (false);
}

void	*hello_darkness(void *data)
{
	t_table	*table;
	int		i;

	i = 0;
	table = (t_table *)data;
	while (!all_threads_ready(&table->table_mutex,
			&table->nbr_of_threads_running, table->num_of_philos))
		;
	while (simulation_finish(table) == false)
	{
		i = -1;
		while (++i < table->num_of_philos && !simulation_finish(table))
		{
			if (is_ded_or_nah(table->philos + i))
			{
				set_bool(&table->table_mutex, &table->end_of_simulation, true);
				write_status(DEDLOL, table->philos + i);
			}
		}
	}
	return (NULL);
}
