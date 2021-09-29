#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"

// char	make_bin(char c)
// {
// }

void	put(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		write(1, &c[i], 1);
		printf("\n");
		i++;
	}
}

int	main(void)
{
	int	i;

	i = (int)'あ';
	printf("utf: %d\n", i);
}
