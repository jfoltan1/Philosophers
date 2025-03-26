/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:49:41 by jfoltan           #+#    #+#             */
/*   Updated: 2024/06/30 18:23:47 by jfoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parse_input(t_table *table, char **argv)
{
	table->num_of_philos = my_atol(argv[1]);
	if (table->num_of_philos < 0)
		exit_error("Error: Wrong arguments!\n");
	table->time_to_die = my_atol(argv[2]) * 1000;
	if (table->time_to_die < 0)
		exit_error("Error: Wrong arguments!\n");
	table->time_to_eat = my_atol(argv[3]) * 1000;
	if (table->time_to_eat < 0)
		exit_error("Error: Wrong arguments!\n");
	table->time_to_sleep = my_atol(argv[4]) * 1000;
	if (table->time_to_sleep < 0)
		exit_error("Error: Wrong arguments!\n");
	if (table->num_of_philos > 200
		|| table->time_to_die < 60e3 || table->time_to_eat < 60e3
		|| table->time_to_sleep < 60e3)
		exit_error("Error: Wrong arguments!\n");
	if (argv[5])
	{
		table->meals_limit = my_atol(argv[5]);
		if (table->meals_limit < 0)
			exit_error("Error: Wrong arguments!\n");
	}
	else
		table->meals_limit = -1;
}
