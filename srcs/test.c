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
	unsigned int	num;
	unsigned char	*unsigned_c;

	unsigned_c = (unsigned char *)c;
	bin = ft_calloc(sizeof(char), 8 * bytes);
	i = bytes - 1;
	while (i >= 0)
	{
		num = (unsigned int)unsigned_c[i];
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

// UTF-8 で何バイトで表現されるか取得
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

void	set(char **bin)
{
	*bin[0] = 'a';
}

int	main(void)
{
	char			*c;
	int				i;
	unsigned int	num;
	unsigned char	*unsigned_c;
	char			*bin;

	c = "a";
	i = 0;
	printf("\n「%s」 \nbytes: %d\n\n", c, get_byte(c));
	bin = bin_from_char(c, get_byte(c));
	printf("bin:  %s\n", bin);
	free(bin);
}
