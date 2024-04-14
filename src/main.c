#include "../includes/philo.h"

int main(int argc, char **argv) 
{
	t_data *data;
	struct timeval time;

	gettimeofday(&time, NULL);

	if (check_args(argc, argv))
		return -1;
	data = init_data(argv,time);
	init_philos(data);
	

	return 0;
}
/*
indexed thread cration now works, now to make them think and sleep, probably after joining thread check time of day and call again ? 
procedure to make them think: 
*/