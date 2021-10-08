/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:03:13 by sosugimo          #+#    #+#             */
/*   Updated: 2021/10/08 16:03:14 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

char	*bin_from_char(char *c)
{
	int				j;
	char			*bin;
	unsigned char	*un_c;
	unsigned int	num;

	un_c = (unsigned char *)c;
	bin = ft_calloc(sizeof(char), 9);
	num = (unsigned int)un_c[0];
	j = 7;
	while (j >= 0)
	{
		bin[j] = '0' + num % 2;
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

void	error_deal(int argc, char *pid)
{
	if (argc <= 2)
	{
		ft_putstr_fd(ERR_NUM_ARG, 1);
		exit(0);
	}
	if (argc >= 4)
	{
		ft_putstr_fd(ERR_ARG_LA, 1);
		exit(0);
	}
	if (ft_strlen(pid) != 5)
	{
		ft_putstr_fd(ERR_ARG_FOM, 1);
		exit(0);
	}
	if (!('0' <= *pid && *pid <= '9'))
	{
		ft_putstr_fd(ERR_ARG_FOM, 1);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	char		*c;
	int			pid;
	char		*bin;

	error_deal(argc, argv[1]);
	pid = ft_atoi(argv[1]);
	c = argv[2];
	while (*c)
	{
		bin = bin_from_char(c);
		send_signal(bin, pid);
		free(bin);
		c++;
	}
}
