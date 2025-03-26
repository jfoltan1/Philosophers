/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:56:27 by jfoltan           #+#    #+#             */
/*   Updated: 2024/06/17 17:57:20 by jfoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	safe_mutex_handle(t_mutex *mutex, t_action action)
{
	if (action == LOCK)
		pthread_mutex_lock(mutex);
	else if (action == UNLOCK)
		pthread_mutex_unlock(mutex);
	else if (action == INIT)
		pthread_mutex_init(mutex, NULL);
	else if (action == DESTROY)
		pthread_mutex_destroy(mutex);
}

void	safe_thread_handle(pthread_t *thread, void *(*foo)(void *),
	t_action action, void *data)
{
	if (action == CREATE)
		pthread_create(thread, NULL, foo, data);
	else if (action == JOIN)
		pthread_join(*thread, NULL);
	else if (action == DETACH)
		pthread_detach(*thread);
}
