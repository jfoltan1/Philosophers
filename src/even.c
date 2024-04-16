#include "../includes/philo.h"
void	even_start(t_data *data)
{
	int i;
	int id;

	i = 0;
	id = 1;
	while (id <= data->num_of_philos)
	{	
		pthread_mutex_lock(data->philo[id]->fork);
		pthread_mutex_lock(data->philo[id + 1]->fork);
		data->philo[id]->state = eating;
		printf("philo %d is eating\n", data->philo[id]->id);
		pthread_mutex_unlock(data->philo[id]->fork);
		pthread_mutex_unlock(data->philo[id + 1]->fork);
		data->philo[id]->time_of_last_meal = gettimeofday(&data->time, NULL);
		data->philo[id]->num_of_meals++;
		data->philo[id]->state = sleeping;
		id = id + 2;
	}
}
// move out the printf statements to a separate function being run by the checker thread.
//base the output on state 
void philosophise(t_data *data)
{
	while (1)
	{
		printf("philo %d is eating\n", state_to_string(data->philo[id]->state));
		
	}
}