/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrn_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiogo <ldiogo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:12:23 by ldiogo            #+#    #+#             */
/*   Updated: 2022/05/03 16:44:11 by ldiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_putnbrn_fd(unsigned int nb, int fd)
{
	int	i;

	i = ft_undeclen (nb);
	if (nb <= 4294967295 && nb >= 0)
	{
		if (nb > 9)
		{
			ft_putnbrn_fd(nb / 10, fd);
			ft_putnbrn_fd(nb % 10, fd);
		}
		else
		{
			ft_putchar_fd(nb + 48, fd);
		}
	}
	return (i);
}
