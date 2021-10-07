#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"

int	test_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*str;

	i = 0;
	if (argc <= 1)
		str = "盗んだバイクで走り出す";
	else
		str = argv[1];
	printf("(ft_)len:  %d\n", ft_strlen(str));
	printf("len:  %lu\n", strlen(str));
	while (str[i])
	{
		printf("[%d] %c\n", i, str[i]);
		i++;
	}
	printf("\n");
}
