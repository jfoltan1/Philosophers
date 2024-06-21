/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:01:24 by jfoltan           #+#    #+#             */
/*   Updated: 2024/06/17 18:19:39 by jfoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	my_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
		*ptr++ = 0;
}

void	*my_calloc(size_t bytes)
{
	void	*ptr;

	ptr = malloc(bytes);
	if (!ptr)
		exit_error("Malloc failed");
	my_bzero(ptr, bytes);
	return (ptr);
}

long	my_atol(const char *str)
{
	long	res;
	int		sign;

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
