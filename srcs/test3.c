#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int	get_byte(char *bin)
{
	int	i;

	i = 0;
	while (bin[i] == '1')
		i++;
	return (i++);
}

char	**split_byte(char *bin)
{
	int		i;
	int		j;
	char	**utf;
	int		bytes;

	i = 0;
	bytes = get_byte(bin);
	printf("bytes:  %d\n", bytes);
	utf = (char **)malloc(sizeof(char *) * (bytes + 1));
	while (i < bytes)
	{
		utf[i] = (char *)malloc(sizeof(char) * 11);
		j = 2;
		utf[i][0] = '0';
		utf[i][1] = 'b';
		while (j <= 9)
		{
			// printf("■■■■■■■■■■■■■■■■■■■■■\n");
			utf[i][j] = *bin;
			// printf("utf [%d][%d]:  %c\n", i, j, utf[i][j]);
			j++;
			bin++;
		}
		utf[i][j] = '\0';
		i++;
	}
	utf[i] = NULL;
	return (utf);
}

void	print_all(char **str, int bytes)
{
	int	i;

	i = 0;
	while (i < bytes)
	{
		printf("(%d) %s\n", i, str[i]);
		i++;
	}
}

void	print_all2(char *str, int bytes)
{
	int	i;

	i = 0;
	while (i < bytes)
	{
		printf("(%d) %c\n", i, str[i]);
		i++;
	}
}

int	atoi_bin(char *str)
{
	int	num;

	return (num);
}

int	main(void)
{
	char	*bin;
	char	**utf;

	// bin = "11100011 10000001 10111101";
	bin = "111000111000000110111101";
	char thinking[4] = {0b11100011, 0b10000001, 0b10111101};
	utf = split_byte(bin);
	print_all(utf, get_byte(bin));
	print_all2(thinking, 4);
	write(1, utf, 3);
	printf("\n");
}
