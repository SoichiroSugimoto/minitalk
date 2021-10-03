#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;

	p = (char *)malloc(size * count);
	if (p == NULL)
		return (0);
	ft_bzero(p, (count * size));
	return ((void *)p);
}

char	*bin_from_char(char *c, int bytes)
{
	int				i;
	int				j;
	char			*bin;
	unsigned char	*un_c;
	unsigned int	num;

	un_c = (unsigned char *)c;
	bin = calloc(sizeof(char), 8 * bytes + 1);
	i = bytes - 1;
	while (i >= 0)
	{
		num = (unsigned int)un_c[i];
		j = 7;
		while (j >= 0)
		{
			bin[8 * i + j] = '0' + num % 2;
			num = num / 2;
			j--;
		}
		i--;
	}
	return (bin);
}

int	get_byte(char *c)
{
	int	bytes;
	int	i;

	bytes = 0;
	i = 7;
	if (!(*c & (1 << 7)))
		return (1);
	while (i >= 4)
	{
		if (*c & (1 << i))
			bytes++;
		else
			return (bytes);
		i--;
	}
	return (bytes);
}

int	main(int argc, char **argv)
{
	char		*c;
	int			i;
	char		*bin;
	int			bytes;

	if (argc <= 0)
	{
		printf("Error %s\n", "NO ARGUMENTS");
		exit(0);
	}
	c = argv[1];
	i = 0;
	bytes = get_byte(c);
	bin = bin_from_char(c, bytes);
	printf("bin:  %s\n", bin);
	free(bin);
	// 11100011 10000001 10000010
}
