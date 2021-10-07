#include "../includes/minitalk.h"

int	get_byte(char c)
{
	int	bytes;
	int	i;

	bytes = 0;
	i = 7;
	if (!(c & (1 << 7)))
		return (1);
	while (i >= 4)
	{
		if (c & (1 << i))
			bytes++;
		else
			return (bytes);
		i--;
	}
	return (bytes);
}

char	*bin_from_char(char *c)
{
	int				i;
	int				j;
	char			*bin;
	unsigned char	*un_c;
	unsigned int	num;

	un_c = (unsigned char *)c;
	bin = calloc(sizeof(char), 9);
	num = (unsigned int)un_c[i];
	j = 7;
	while (j >= 0)
	{
		bin[8 * i + j] = '0' + num % 2;
		num = num / 2;
		j--;
	}
	return (bin);
}

void	send_signal(char *bin, int pid)
{
	int	i;

	i = 0;
	while (bin[i])
	{
		if (bin[i] == '1')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	char		*c;
	int			pid;
	char		*bin;

	if (argc <= 0)
	{
		printf("Error %s\n", "NO ARGUMENTS");
		exit(0);
	}
	pid = atoi(argv[1]);
	c = argv[2];
	while (*c)
	{
		bin = bin_from_char(c);
		send_signal(bin, pid);
		free(bin);
		c++;
	}
}
