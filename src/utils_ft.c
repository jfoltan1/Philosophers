/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:31:28 by jfoltan           #+#    #+#             */
/*   Updated: 2024/04/15 15:02:37 by jfoltan          ###   ########.fr       */
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
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write((unsigned int)fd, &s[i], 1);
		i++;
	}
}

static int	ft_isneg(long f)
{
	if (f < 0)
		return (1);
	return (0);
}

static	int	ft_len(long l)
{
	int	i;

	i = 0;
	if (ft_isneg(l))
	{
		i++;
		l = l * -1;
	}
	while (l >= 10)
	{
		l = l / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		i;
	long	f;

	f = n;
	i = ft_len(f);
	if (f < 0)
		f = f * -1;
	ptr = (char *)malloc(sizeof(char) * i + 2);
	if (!ptr)
		return (NULL);
	ptr[i + 1] = 0;
	while (i >= 0)
	{
		ptr[i--] = f % 10 + '0';
		f = f / 10;
	}
	if (n < 0)
		ptr[0] = '-';
	return (ptr);
}
