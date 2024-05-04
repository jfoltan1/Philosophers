/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:55:59 by jfoltan           #+#    #+#             */
/*   Updated: 2024/05/04 09:47:04 by jfoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
pthread_t	create_thread(void)
{
	pthread_t philo;
	philo = 0;
	
	return philo;
}
long	gettime(int time_code)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		printf("Error: gettimeofday\n");
	if (MILLISECOND == time_code)
		return (tv.tv_sec * 1e3 + tv.tv_usec / 1e3);
	else if (MICROSECOND == time_code)
		return (tv.tv_sec * 1e6 + tv.tv_usec);
	else if (SECONDS == time_code)
		return (tv.tv_sec + tv.tv_usec / 1e6);
	return (1337);
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
t_data 	*init_data(char **argv)
{
	t_data *data;

	
	data = (t_data *)ft_calloc(1, sizeof(t_data));
	data->running = true;
	pthread_mutex_init(&data->dead_lock, NULL);
	pthread_mutex_init(&data->meal_lock, NULL);
	pthread_mutex_init(&data->write_lock, NULL);
	data->start_time = gettime(MILLISECOND);
	//data->start_time = 0;
	data->philo = (t_philo **)ft_calloc(ft_atoi(argv[1]), sizeof(t_philo *));
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
