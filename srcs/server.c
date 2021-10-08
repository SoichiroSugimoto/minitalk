/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:03:41 by sosugimo          #+#    #+#             */
/*   Updated: 2021/10/08 16:03:42 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

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
	if (num == 8)
	{
		write(1, &c, 1);
		num = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_handler = handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("%d\n", getpid());
	while (1)
		pause();
	return (0);
}
