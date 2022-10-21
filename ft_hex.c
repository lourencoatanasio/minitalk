/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiogo <ldiogo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:19:06 by ldiogo            #+#    #+#             */
/*   Updated: 2022/05/03 16:37:04 by ldiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_hex(unsigned int dec, char *str)
{
	int		x;
	int		if0;
	int		i;
	char	*hexnum;

	if0 = 0;
	x = 0;
	hexnum = (char *)malloc((ft_intlen(dec) + 1) * sizeof(char));
	if (dec == 0)
	{
		ft_putchar_fd('0', 1);
		if0 = 1;
	}
	while (dec != 0)
	{
		hexnum[x++] = str[dec % 16];
		dec /= 16;
	}
	hexnum[x] = '\0';
	i = ft_strlen(hexnum);
	ft_putstr_fd(ft_strrev(hexnum), 1);
	if (if0 == 1)
		i = 1;
	free (hexnum);
	return (i);
}
