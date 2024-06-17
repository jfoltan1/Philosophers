#include "philo.h"

void safe_mutex_handle(t_mutex *mutex, t_action action)
{
	if (action == LOCK)
		pthread_mutex_lock(mutex);
	else if (action == UNLOCK)
		pthread_mutex_unlock(mutex);
	else if (action == INIT)
		pthread_mutex_init(mutex, NULL);
	else if (action == DESTROY)
		pthread_mutex_destroy(mutex); //TODO maybe will need the return value of these and handle them safer-y

}
void safe_thread_handle(pthread_t *thread, void *(*foo)(void *),t_action action,void *data)
{
	if (action == CREATE)
		pthread_create(thread, NULL, foo, data);
	else if (action == JOIN)
		pthread_join(*thread, NULL);
	else if (action == DETACH)
		pthread_detach(*thread);
}