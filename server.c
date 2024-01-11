/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoubby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 10:10:04 by echoubby          #+#    #+#             */
/*   Updated: 2024/01/11 09:40:15 by echoubby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../printf_git/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

void	ft_putchar_fd(char c, int fd);

void	handler(int signum)
{
	static int	bit;
	static int	decimal;

	if (signum == SIGUSR1)
		decimal |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(decimal, 1);
		bit = 0;
		decimal = 0;
	}
}

int	main(void)
{
	ft_printf("Welcome To My Server!\n");
	ft_printf("My Server PID is: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		pause();
	}
	return (0);
}
