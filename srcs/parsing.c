#include "philo.h"
static long ft_atol(const char *str)
{
	long res;
	int sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	if (res > INT_MAX)
		exit_error("Error: Number is too big\n");
	return (res * sign);
}
void parse_input(t_table *table, char **argv)
{
	table->num_of_philos = ft_atol(argv[1]); // TODO check for valid input ??
	table->time_to_die = ft_atol(argv[2]) * 1000;
	table->time_to_eat = ft_atol(argv[3]) * 1000;
	table->time_to_sleep = ft_atol(argv[4]) * 1000;
	if (table->time_to_die < 60000
		|| table->time_to_eat < 60000
		|| table->time_to_sleep < 60000)
		exit_error("Given time values are too low!\n"); // TODO are they ?
	if (argv[5])
		table->meals_limit = ft_atol(argv[5]);
	else
		table->meals_limit = -1;
}