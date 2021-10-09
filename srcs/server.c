/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:03:41 by sosugimo          #+#    #+#             */
/*   Updated: 2021/10/09 08:36:08 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

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
