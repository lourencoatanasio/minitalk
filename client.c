/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiogo <ldiogo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:36:08 by ldiogo            #+#    #+#             */
/*   Updated: 2022/10/21 15:19:10 by ldiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sendsignal(char *str, int pid)
{
	int	i;

	i = 0;
	if (!str)
	{
		while (i < 8)
		{
			kill(pid, SIGUSR1);
			i++;
		}
	}
	while (i < 8)
	{
		if (str[i] == '0')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(100);
	}
}

void	sendsig(int pid, char **argv)
{
	int		*i;
	char	send[9];

	i = (int [3]){0, 7, 0};
	while (argv[2][i[0]])
	{
		i[2] = argv[2][i[0]];
		while (i[2] != 0)
		{
			if (i[2] % 2 == 1)
				send[i[1]--] = '1';
			else
				send[i[1]--] = '0';
			i[2] /= 2;
		}
		while (i[1] >= 0)
			send[i[1]--] = '0';
		send[8] = '\0';
		sendsignal(send, pid);
		i[0]++;
		i[1] = 7;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;

	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	sendsig(pid, argv);
	i = 0;
	while (i < 8)
	{
		kill(pid, SIGUSR2);
		usleep(100);
		i++;
	}
}
