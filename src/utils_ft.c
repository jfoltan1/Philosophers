/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:31:28 by jfoltan           #+#    #+#             */
/*   Updated: 2023/12/16 12:31:34 by jfoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*se;

	i = 0;
	se = (unsigned char *)s;
	while (i < n)
	{
		se[i] = 0;
		i++;
	}
	s = se;
}

int	ft_atoi(const char *nptr)
{
	long	i;
	long	res;
	int		sign;

	res = 0;
	i = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == ' '))
		i++;
	if ((nptr[i] == '-' || nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (res * sign);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(size * nmemb);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * nmemb);
	return (ptr);
}
