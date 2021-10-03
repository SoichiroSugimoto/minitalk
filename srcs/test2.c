#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"

void	put_prefix(char *bin)
{
	*bin = '0';
	bin++;
	*bin = 'b';
	bin++;
}

char	*bin_to_char(char	*bin, int bytes)
{
	char	**c;
	int		i;

	i = 0;
	c = (char **)malloc(sizeof(int) * bytes);
	while (i <= bytes)
	{
		*c = (char *)malloc(sizeof(int) * 8);
	}
	return (c);
}

// int	one_byte(char *c)
// {
// 	char	one_byte[8];
// 	int		res;

// 	ft_strlcpy(one_byte, c, 8);
// 	res = ft_atoi(one_byte);
// }

int	get_byte(char *bin)
{
	int	i;

	i = 0;
	while (bin[i] == '1')
		i++;
	return (i++);
}

int	main(void)
{
	char	*bin;
	int		bytes;

	bin = "11100011 10000001 10111101";
	// bin = "01100001";
	bytes = get_byte(bin);
	printf("Bytes:  %d\n", bytes);

	char test[1] = {0b01100001};
    write(1, test, 1);
	printf("\n");
}
