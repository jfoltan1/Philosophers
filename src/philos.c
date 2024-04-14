/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:07:15 by jfoltan           #+#    #+#             */
/*   Updated: 2024/04/14 12:37:16 by jfoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
void *routine(void  *arg)
{
	t_data *data;
	int		a;

	data = (t_data *)arg;
	a = data->num_of_philos;
	
	if (a % 2 == 0)
		//even from left fork.
		//easy to divide group 1 starts and then 2 etc..
		even_start(data);
	else if ( a % 2 != 0)
	{
		//all start from sleeping
		//odd from right fork
		//the odd one altering to other groups.
		
	}
	
	/*//t_data *d;
	static int i = 0;

	//d = (t_data *)data;

	printf("Hello from thread %d\n", ((t_data *)data)->philo[i]->id); //bad
	i++;
	fflush(stdout);
	return NULL;*/
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
		pthread_create(&data -> philo[i] -> philo_thread,NULL, &routine, (void *)data);	//probably in routine ?
		pthread_join(data -> philo[i] -> philo_thread, NULL); // probably in routine ? 
		pthread_mutex_init(data -> philo[i] -> fork, NULL);\
		i++;
	}
}