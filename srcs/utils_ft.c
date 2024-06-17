#include "philo.h"

static void my_bzero(void *s, size_t n)
{
	unsigned char *ptr;

	ptr = (unsigned char *)s;
	while (n--)
		*ptr++ = 0;
}
void *my_calloc(size_t bytes)
{
	void *ptr;

	ptr = malloc(bytes);
	if (!ptr)
		exit_error("Malloc failed");
	my_bzero(ptr, bytes);
	return (ptr);
}