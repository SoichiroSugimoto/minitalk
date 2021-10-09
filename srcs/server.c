/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:03:41 by sosugimo          #+#    #+#             */
/*   Updated: 2021/10/09 17:30:26 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static char	*itoa2(long int n, char *p, int i)
{
	if (n < 10)
	{
		p[i] = '0' + n;
		i--;
	}
	else
	{
		p[i] = '0' + n % 10;
		n = n / 10;
		i--;
		itoa2(n, p, i);
	}
	return (p);
}

static int	dgt_mes(long int n)
{
	int	len;

	len = 1;
	while (n >= 10 || n <= -10)
	{
		n /= 10;
		len++;
	}
	if (n < 0)
		len++;
	return (len);
}

char	*ft_itoa(int n)
{
	char		*p;
	int			len;
	int			i;
	long int	l;

	len = dgt_mes(n);
	l = (long int)n;
	i = len;
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (NULL);
	if (l < 0)
	{
		p[0] = '-';
		l *= -1;
	}
	p[i] = '\0';
	i--;
	itoa2(l, p, i);
	return (p);
}

void	handler(int sig)
{
	static char	c;
	static int	num;

	c = c << 1;
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
	char				*pid;

	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_handler = handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = ft_itoa(getpid());
	ft_putstr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	free(pid);
	while (1)
		pause();
	return (0);
}
