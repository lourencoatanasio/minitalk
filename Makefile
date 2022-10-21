# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldiogo <ldiogo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 17:38:27 by ldiogo            #+#    #+#              #
#    Updated: 2022/05/02 15:00:17 by ldiogo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



SERVER_SRCS		=	server.c ft_atoi.c  ft_declen.c  ft_hex.c  ft_hexp.c  ft_intlen.c  ft_putchar_fd.c  ft_putnbr_fd.c  ft_putnbrn_fd.c  ft_putstr_fd.c  ft_strlen.c  ft_strrev.c  ft_undeclen.c printf.c\

CLIENT_SRCS		=	client.c ft_atoi.c  ft_declen.c  ft_hex.c  ft_hexp.c  ft_intlen.c  ft_putchar_fd.c  ft_putnbr_fd.c  ft_putnbrn_fd.c  ft_putstr_fd.c  ft_strlen.c  ft_strrev.c  ft_undeclen.c printf.c\

RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror

SERVER		= server

CLIENT		= client

all:		$(SERVER) $(CLIENT)

$(SERVER):	$(SERVER_SRCS)
			@$(CC) -o $(SERVER) $(SERVER_SRCS)

$(CLIENT):	$(CLIENT_SRCS)
			@$(CC) -o $(CLIENT) $(CLIENT_SRCS)

clean:
			@$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)

fclean:		clean
			@$(RM) $(SERVER) $(CLIENT)

re:			fclean $(SERVER) $(CLIENT)
