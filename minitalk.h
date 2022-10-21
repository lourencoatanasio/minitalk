/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiogo <ldiogo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:00:42 by ldiogo            #+#    #+#             */
/*   Updated: 2022/10/18 16:01:21 by ldiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <signal.h>

int		ft_printf(const char *s, ...);
int		ft_putchar_fd(char c, int fd);
int		ft_putnbr_fd(int nb, int fd);
int		ft_putnbrn_fd(unsigned int nb, int fd);
int		ft_intlen(unsigned long i);
int		ft_strlen(char *str);
int		ft_putstr_fd(char *s, int fd);
int		ft_declen(int i);
int		ft_undeclen(unsigned int i);
int		ft_hex(unsigned int dec, char *str);
char	*ft_strrev(char *str);
int		ft_hexp(unsigned long dec, char *str);
void	ft_putnbr(int nb, int fd);
int		ft_atoi(const char *str);

#endif
