#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

//void	handler(int sig)
//{
//	write(1, "done\n", 5);
//}

//void	handler1(int sig)
//{
//	sleep(10);
//	write(1, "done1\n", 6);
//}

// SIGUSR1 → 1
// SIGUSR2 → 0
// 01110010
// 21112212

static int	ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n / 10)
		ft_putnbr_fd(n / 10, fd);
	else
		write(fd, "-", n < 0);
	write(fd, &"0123456789"[ft_abs(n % 10)], 1);
}

void	print_bit(int num)
{
	if ((num / 2) == 0)
		return ;
	num /= 2;
	print_bit(num);
	ft_putnbr_fd(num % 2, 1);
}

void	handler(int sig)
{
	static char	c;
	static int	bytes;
	static int	num;
	static int	i;

	c = c << 1;
	if (sig == SIGUSR1 && num == bytes && i == 0)
		bytes++;
	if (sig == SIGUSR2 && num == 0)
		bytes++;
	if (sig == SIGUSR2)
		i = 1;
	if (sig == SIGUSR1)
		c += 1;
	num++;
	// printf("[%d] (int)c:  %d  bytes:  %d  i:  %d\n", num, (int)c, bytes, i);
	if (num == 8)
	{
		write(1, &c, 1);
		num = 0;
		// write(1, "\nc(binary) = ", 14);
		// print_bit((int)c);
	}
}

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask); // mask 初期化
	sigaddset(&sa.sa_mask, SIGUSR1); // maskの設定
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_handler = handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("%d\n", getpid());
	while(1)
		pause(); // signalが来るまで待機
	return (0);
}
