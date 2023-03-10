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

int	*binvert(int c)
{
	int	*arraybin;
	int	i;

	i = 7;
	arraybin = malloc(8 * sizeof(int));
	while ((c) != 0)
	{
		arraybin[i] = c % 2;
		c /= 2;
		i--;
	}
	while (i >= 0)
		arraybin[i--] = 0;
	return (arraybin);
}

void	sigsend(int *array,	int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (array[i] == 0)
		{
			kill(pid, SIGUSR1);
			usleep(100);
		}
		else if (array[i] == 1)
		{
			kill(pid, SIGUSR2);
			usleep(100);
		}
		i++;
	}
	free(array);
}

//void	sendsig(int pid, char **argv)
//{
//	int		*i;
//	char	send[9];
//
//	i = (int [3]){0, 7, 0};
//	while (argv[2][i[0]])
//	{
//		i[2] = argv[2][i[0]];
//		while (i[2] != 0)
//		{
//			if (i[2] % 2 == 1)
//				send[i[1]--] = '1';
//			else
//				send[i[1]--] = '0';
//			i[2] /= 2;
//		}
//		while (i[1] >= 0)
//			send[i[1]--] = '0';
//		send[8] = '\0';
//		sendsignal(send, pid);
//		i[0]++;
//		i[1] = 7;
//	}
//}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;
	int		input;

	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i] != '\0')
	{
		input = ft_isprint((int)(argv[2][i]));
		sigsend(binvert(input), pid);
		i++;
	}
	i = 0;
	while (i++ < 8)
	{
		kill(pid, SIGUSR2);
		usleep(100);
	}
}
