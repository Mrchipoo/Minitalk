/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoubby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 10:10:04 by echoubby          #+#    #+#             */
/*   Updated: 2024/05/10 09:40:15 by echoubby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

void	ft_putnbr(unsigned long long n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr(char *s);


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
	int i;

	i = getpid();
	ft_putstr("Welcome To My Server!\n");
	ft_putstr("My Server PID is:");
	ft_putnbr(i);
	ft_putstr("\n");
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		pause();
	}
	return (0);
}