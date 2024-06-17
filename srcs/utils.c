/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:01:58 by jfoltan           #+#    #+#             */
/*   Updated: 2024/06/17 18:28:16 by jfoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	args_check(int argc)
{
	if (argc != 5 && argc != 6)
		return (0);
	return (1);
}

long	gettime(t_time_code time_code)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		exit_error("Error: gettimeofday failed");
	if (time_code == SECONDS)
		return (tv.tv_sec + tv.tv_usec / 1000000);
	else if (time_code == MILISECONDS)
		return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
	else if (time_code == MICROSECONDS)
		return (tv.tv_sec * 1000000 + tv.tv_usec);
	else
		exit_error("Error: wrong time_code");
	return (0);
}

void	my_usleep(long usec, t_table *table)
{
	long	start_time;
	long	elapsed_time;
	long	remaining_time;

	start_time = gettime(MICROSECONDS);
	while (gettime(MICROSECONDS) - start_time < usec)
	{
		if (simulation_finish(table))
			break ;
		elapsed_time = gettime(MICROSECONDS) - start_time;
		remaining_time = usec - elapsed_time;
		if (remaining_time > 1000)
			usleep(remaining_time / 2);
		else
			while (gettime(MICROSECONDS) - start_time < usec)
				;
	}
}

void	exit_error(char *str)
{
	printf("%s\n", str);
	exit(EXIT_FAILURE);
}
