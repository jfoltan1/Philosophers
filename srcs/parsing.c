/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:49:41 by jfoltan           #+#    #+#             */
/*   Updated: 2024/06/17 18:24:53 by jfoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parse_input(t_table *table, char **argv)
{
	table->num_of_philos = my_atol(argv[1]);
	table->time_to_die = my_atol(argv[2]) * 1000;
	table->time_to_eat = my_atol(argv[3]) * 1000;
	table->time_to_sleep = my_atol(argv[4]) * 1000;
	if (argv[5])
		table->meals_limit = my_atol(argv[5]);
	else
		table->meals_limit = -1;
}
