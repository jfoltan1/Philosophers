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
		pthread_mutex_unlock(data->philo[id]->fork);
		pthread_mutex_unlock(data->philo[id + 1]->fork);
		data->philo[id]->time_of_last_meal = gettimeofday(data->time);
		data->philo[id]->num_of_meals++;
		data->philo[id]->state = sleeping;
		id = id + 2;
	}
}