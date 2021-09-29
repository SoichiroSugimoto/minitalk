#include "../includes/minitalk.h"

int	main(int argc, char **argv)
{
	int	pid;

	pid = ft_atoi(argv[1]);
	kill(pid, SIGUSR1);
}
