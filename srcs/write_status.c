/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:03:32 by jfoltan           #+#    #+#             */
/*   Updated: 2024/06/17 17:55:52 by jfoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_status(t_philo_status status, t_philo *philo)
{
	long	elapsed;

	elapsed = gettime(MILISECONDS) - philo->table->start_time;
	if (get_bool(&philo->philo_mutex, &philo->is_full))
		return ;
	safe_mutex_handle(&philo->table->write_mutex, LOCK);
	if ((status == FIRST_FORK || status == SECOND_FORK)
		&& !simulation_finish(philo->table))
		printf("%-6ld %d has taken a fork\n", elapsed, philo->id);
	else if (status == EATING && !simulation_finish(philo->table))
		printf("%-6ld %d is eating\n", elapsed, philo->id);
	else if (status == SLEEPING && !simulation_finish(philo->table))
		printf("%-6ld %d is sleeping\n", elapsed, philo->id);
	else if (status == THINKING && !simulation_finish(philo->table))
		printf("%-6ld %d is thinking\n", elapsed, philo->id);
	else if (status == DEDLOL)
		printf("%-6ld %d died\n", elapsed, philo->id);
	safe_mutex_handle(&philo->table->write_mutex, UNLOCK);
}
