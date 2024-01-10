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
client_src =client.c
server_src = server.c
Libft = ft_atoi.c ft_putchar_fd.c
SERVER = server
CLIENT = client
PRINTF = ./printf_git

all = $(SERVER) $(CLIENT)

all:
	@make -s -C $(PRINTF)
	cp $(PRINTF)/libftprintf.a .
	$(CC) $(Gflag) server.c libftprintf.a $(Libft) -o $(SERVER)
	$(CC) $(Gflag) client.c libftprintf.a  $(Libft) -o $(CLIENT)
	rm -f libftprintf.a
	@echo "Server And Client Are Ready!"
clean:
	@make fclean -C $(PRINTF)
fclean: clean
	rm -f server client
re: fclean all
.PHONY: all clean fclean




