/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:08:57 by jfoltan           #+#    #+#             */
/*   Updated: 2024/04/23 16:32:00 by jfoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
void cleanup(t_data *data)
{
	int i;
	int num_of_philos;
	
	i = -1;
	num_of_philos = data->philo[0]->num_of_philos;
	while (++i < num_of_philos)
		pthread_join(data->philo[i]->philo_thread, NULL);
	
}
int main(int argc, char **argv) 
{
	t_data *data;
	struct timeval time;
	char *fake_argv[6];

	gettimeofday(&time, NULL);
	if (argc == 1)
		{
			fake_argv[1] = ft_itoa(4);
			fake_argv[2] = ft_itoa(200);
			fake_argv[3] = ft_itoa(200);
			fake_argv[4] = ft_itoa(200);
			fake_argv[5] = ft_itoa(6);
			data = init_data(fake_argv);
			init_philos(fake_argv, data);
		}
	//if (check_args(argc, argv))
		//return -1;
	else
	{
		data = init_data(argv);
			init_philos(fake_argv, data);
	}
		cleanup(data);
	return 0;
}
/*
indexed thread cration now works, now to make them think and sleep, probably after joining thread check time of day and call again ? 
procedure to make them think: 
uncomment number of suppers.
https://medium.com/@ruinadd/philosophers-42-guide-the-dining-philosophers-problem-893a24bc0fe2
TODO:
fixes:
-philos should be named from 1 

routine:
threads now created.
timestamp should work.
basic messaging works 
probably have to have a mutex for states ? 


 

test
cleanup
test
*/