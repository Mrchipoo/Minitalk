# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: echoubby <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/26 16:47:41 by echoubby          #+#    #+#              #
#    Updated: 2023/11/26 17:16:14 by echoubby         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
src = ft_printf.c ft_handler.c ft_putnbr.c ft_putstr.c ft_strlen.c
CFLAGS = -Wall -Werror -Wextra
object = $(src:.c=.o)
NAME = libftprintf.a


all: $(NAME)

$(NAME): $(object)
	ar rsc $@ $^
$(object): $(src)
	$(CC) $(CFLAGS) $(src) -c
clean:
	rm -f $(object)
fclean: clean
	rm -f $(NAME)
re: fclean $(NAME)
.PHONY: all clean fclean	
