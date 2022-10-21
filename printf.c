/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiogo <ldiogo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:19:11 by ldiogo            #+#    #+#             */
/*   Updated: 2022/10/18 15:37:36 by ldiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "minitalk.h"

int	ft_flag(char s, va_list args)
{
	int	bc;

	bc = 0;
	if (s == 'c')
		bc += ft_putchar_fd(va_arg(args, int), 1);
	if (s == 's')
		bc += ft_putstr_fd(va_arg(args, char *), 1);
	if (s == 'i' || s == 'd')
		bc += ft_putnbr_fd(va_arg(args, int), 1);
	if (s == '%')
		bc += ft_putchar_fd('%', 1);
	if (s == 'x')
		bc += ft_hex(va_arg(args, int), "0123456789abcdef");
	if (s == 'X')
		bc += ft_hex(va_arg(args, int), "0123456789ABCDEF");
	if (s == 'u')
		bc += ft_putnbrn_fd(va_arg(args, unsigned int), 1);
	if (s == 'p')
	{
		bc += 2;
		write (1, "0x", 2);
		bc += ft_hexp(va_arg(args, long), "0123456789abcdef");
	}
	return (bc);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		bc;

	va_start (args, s);
	bc = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			bc += ft_flag(s[++i], args);
			i++;
		}
		else
		{
			bc += ft_putchar_fd(s[i], 1);
			i++;
		}
	}
	return (bc);
}
