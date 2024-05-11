# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: echoubby <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 12:03:55 by echoubby          #+#    #+#              #
#    Updated: 2024/01/09 09:27:47 by echoubby         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Gflag = -Wall -Werror -Wextra
CC = cc
Libft = ft_atoi.c ft_putchar_fd.c ft_isdigit.c ft_putstr.c ft_putnbr.c
SERVER = server
CLIENT = client
SERVER_bonus=server_bonus
CLIENT_bonus=client_bonus


all:$(SERVER) $(CLIENT)
	@echo "Server And Client Are Ready!"
$(SERVER):
	$(CC) $(Gflag) server.c  $(Libft) -o $(SERVER)
$(CLIENT):
	$(CC) $(Gflag) client.c  $(Libft) -o $(CLIENT)
bonus:$(SERVER_bonus) $(CLIENT_bonus)
	@echo "Server And Client Are Ready!"
$(SERVER_bonus):
	$(CC) $(Gflag) server_bonus.c $(Libft) -o $(SERVER_bonus)
$(CLIENT_bonus):
	$(CC) $(Gflag) client_bonus.c $(Libft) -o $(CLIENT_bonus)
fclean:
	rm -f server client
	rm -f server_bonus client_bonus
re: fclean all
.PHONY: all  fclean




