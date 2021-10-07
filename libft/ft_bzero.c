#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	int		i;
	char	*st;

	i = 0;
	st = (char *)s;
	while ((size_t)i < n)
	{
		st[i] = 0;
		i++;
	}
}