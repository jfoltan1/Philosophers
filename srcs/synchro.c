/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   synchro.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:59:34 by jfoltan           #+#    #+#             */
/*   Updated: 2024/06/29 15:41:28 by jfoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_on_threads(t_table *table)
{
	while (!get_bool(&table->table_mutex, &table->its_go_time))
		;
}

bool	all_threads_ready(t_mutex *mutex, long *threads, long philo_nbr)
{
	bool	ret;

	ret = false;
	safe_mutex_handle(mutex, LOCK);
	if (*threads == philo_nbr)
		ret = true;
	safe_mutex_handle(mutex, UNLOCK);
	return (ret);
}

void	increase_long(t_mutex *mutex, long *value)
{
	safe_mutex_handle(mutex, LOCK);
	(*value)++;
	safe_mutex_handle(mutex, UNLOCK);
}

void	godricks_hat(t_philo *philo)
{
	if (philo->table->num_of_philos % 2 == 0)
	{
		if (philo->id % 2 == 0)
			my_usleep(3e4, philo->table);
	}
	else
		if (philo->id % 2)
			think(philo, true);
}
