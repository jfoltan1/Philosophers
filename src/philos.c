/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:07:15 by jfoltan           #+#    #+#             */
/*   Updated: 2023/12/16 13:14:36 by jfoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
void *routine(void *data)
{
	//t_data *d;
	static int i = 0;

	//d = (t_data *)data;

	printf("Hello from thread %d\n", ((t_data *)data)->philo[i]->id); //bad
	i++;
	fflush(stdout);
	return NULL;
}
void init_philos(t_data	*data)
{
	int i;
	int a;
	t_philo **philo;
	
	philo = malloc(sizeof(t_philo **));
	data->philo = philo;
	//imlement even and odd
	i = 0;
	a = data->num_of_philos;
	while(i <= a)
	{
		data -> philo[i] = malloc(sizeof(t_philo));
		data -> philo[i]->id = i;
		data -> philo[i]->philo_thread = create_thread();
		pthread_create(&data -> philo[i] -> philo_thread,NULL, &routine, (void *)data);		
		pthread_join(data -> philo[i] -> philo_thread, NULL);
		// create mutex
		// create fork
		// create philo
		// create philo thread
		i++;
	}
	
}