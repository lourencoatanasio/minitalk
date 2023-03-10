/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiogo <ldiogo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:36:48 by ldiogo            #+#    #+#             */
/*   Updated: 2022/10/21 15:40:42 by ldiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
		return (nb * ft_recursive_power(nb, power - 1));
}

int	decoder(char *str)
{
	int	c;
	int	r;

	c = 7;
	r = 0;
	while (c >= 0)
	{
		if (str[c] == '1')
			r += 1 * ft_recursive_power(2, 7 - c);
		c--;
	}
	return (r);
}

void	ft_sighand(int sig)
{
	int			g_i;
	char		str[9];

	str[8] = '\0';
	if (sig == 10)
		str[g_i] = '0';
	else if (sig == 12)
		str[g_i] = '1';
	g_i++;
	if (g_i == 8)
	{
		if (str[0] == '0')
		{
			str[g_i] = '\0';
			ft_printf("%c", decoder(str));
		}
		else
			ft_printf("\n");
		g_i = 0;
	}
}

int	main(void)
{
	ft_printf("%i\n", getpid());
	signal(SIGUSR1, ft_sighand);
	signal(SIGUSR2, ft_sighand);
	while (1)
		;
}
