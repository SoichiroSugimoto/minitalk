#include "../includes/minitalk.h"

void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
	{
		sleep(10);
		write(1, "a", 1);
	}
	else if (signal == SIGUSR2)
	{
		write(1, "b", 1);
	}
}

int	main(void)
{
	int					pid;
	int					n;
	struct sigaction	sa;

	bzero(&sa, sizeof(sigaction));
	sa.sa_handler = &signal_handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = getpid();
	printf("pid:  %d\n", pid);
	while (1)
		pause();
}
