#include "philo.h"

void set_bool(t_mutex *mutex, bool *dest,bool value)
{
	safe_mutex_handle(mutex, LOCK);
	*dest = value;
	safe_mutex_handle(mutex, UNLOCK);
}
bool get_bool(t_mutex *mutex, bool *value)
{
	bool ret;

	safe_mutex_handle(mutex, LOCK);
	ret = *value;
	safe_mutex_handle(mutex, UNLOCK);
	return (ret);
}
long get_long(t_mutex *mutex, long *value)
{
	long ret;

	safe_mutex_handle(mutex, LOCK);
	ret = *value;
	safe_mutex_handle(mutex, UNLOCK);
	return (ret);
}
void set_long(t_mutex *mutex, long *dest,long value)
{
	safe_mutex_handle(mutex, LOCK);
	*dest = value;
	safe_mutex_handle(mutex, UNLOCK);
}
bool simulation_finish(t_table *table)
{
	return (get_bool(&table->table_mutex, &table->end_of_simulation));
}