#include "../includes/philo.h"
void *routine(void *data)
{
	if (((t_data *)data) -> num_of_philos % 2 == 0)
		even_start((t_data *)data);
	//else if ((t_data *)data -> num_of_philos % 2 != 0)
		//odd_start((t_data *)data);
	fflush(stdout);
	return NULL;
}
int main(int argc, char **argv) 
{
	t_data *data;
	struct timeval time;
	char *fake_argv[5];

	gettimeofday(&time, NULL);
	if (argc == 1)
		{
			fake_argv[1] = ft_itoa(4);
			fake_argv[2] = ft_itoa(200);
			fake_argv[3] = ft_itoa(200);
			fake_argv[4] = ft_itoa(200);
			data = init_data(fake_argv,time);
		}
	//if (check_args(argc, argv))
		//return -1;
	else
		data = init_data(argv,time);
	init_philos(data);

	return 0;
}
/*
indexed thread cration now works, now to make them think and sleep, probably after joining thread check time of day and call again ? 
procedure to make them think: 
uncomment number of suppers.
https://medium.com/@ruinadd/philosophers-42-guide-the-dining-philosophers-problem-893a24bc0fe2
*/