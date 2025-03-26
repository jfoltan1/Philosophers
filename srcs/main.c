/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:42:37 by jfoltan           #+#    #+#             */
/*   Updated: 2024/06/21 21:51:17 by jfoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	goodbye(t_table *table)
{
	t_philo	*philo;
	int		i;

	i = -1;
	while (++i < table->num_of_philos)
	{
		philo = table->philos + i;
		safe_mutex_handle(&philo->philo_mutex, DESTROY);
	}
	safe_mutex_handle(&table->write_mutex, DESTROY);
	safe_mutex_handle(&table->table_mutex, DESTROY);
	free(table->forks);
	free(table->philos);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (args_check(argc))
	{
		parse_input(&table, argv);
		set_the_table(&table);
		philosophise(&table);
		goodbye(&table);
	}
	else
		exit_error("Error: Wrong arguments!\n");
}

/*
TODO:
checks other TODOs:
memory leaks - pthread ? fsanitize ? 
eval sheet
*/
