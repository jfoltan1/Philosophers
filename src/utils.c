/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:55:59 by jfoltan           #+#    #+#             */
/*   Updated: 2024/04/16 10:39:32 by jfoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
pthread_t	create_thread(void)
{
	pthread_t philo;
	philo = 0;
	
	return philo;
}
int	get_time_to_die(char **argv)
{
	int time_to_die;
	
	if (ft_atoi(argv[1]) % 2 == 0)
		time_to_die = (ft_atoi(argv[3]) + ft_atoi(argv[4])) + 10; //maybe will change
	else
		time_to_die = (ft_atoi(argv[3]) * 2) + ft_atoi(argv[4]) + 10; //maybe will change
	return time_to_die;
}
t_data 	*init_data(char **argv,struct timeval time)
{
	t_data *data;
	
	data = malloc(sizeof(t_data));
	data->time = time;
	data->time_on_start = gettimeofday(&time, NULL);
	data->num_of_philos = ft_atoi(argv[1]);
	data->time_to_die = get_time_to_die(argv);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	//if (argv[5])
		//data->num_of_times_each_philo_must_eat = ft_atoi(argv[5]);
	//else
		data->num_of_times_each_philo_must_eat = -1;
	return data;
}
int	check_args(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		printf("%d\n", ft_atoi(argv[0]));
		printf("Error: Wrong number of arguments\n");
		return -1;
	}
		printf("%d\n", ft_atoi(argv[1]));
	if (ft_atoi(argv[1]) < 1)
	{

		printf("Error: Wrong number of philosophers\n");
		return -1;
	}
		printf("%d\n", ft_atoi(argv[2]));
	if (ft_atoi(argv[2]) < 0)
	{
		
		printf("Error: Wrong time to die\n");
		return -1;
	}
		printf("%d\n", ft_atoi(argv[3]));
	if (ft_atoi(argv[3]) < 0)
	{
		
		printf("Error: Wrong time to eat\n");
		return -1;
	}
		printf("%d\n", ft_atoi(argv[4]));
	if (ft_atoi(argv[4]) < 0)
	{
		
		printf("Error: Wrong time to sleep\n");
		return -1;
	}
	if (argc == 6 && ft_atoi(argv[5]) < 0)
	{
		
		printf("Error: Wrong number of times each philosopher must eat\n");
		return -1;
	}
	fflush(stdout);
	return 0;
}
char *state_to_string(t_state state)
{
	if (state == eating)
		return "eating";
	else if (state == sleeping)
		return "sleeping";
	else if (state == thinking)
		return "thinking";
	return "error";
}