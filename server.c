/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoubby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 10:10:04 by echoubby          #+#    #+#             */
/*   Updated: 2024/01/08 11:58:09 by echoubby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../printf_git/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

void	ft_putchar_fd(char c, int fd);

int	square_dyali(int weight, int bit)
{
	while (bit > 0)
	{
		weight *= 2;
		bit--;
	}
	return (weight);
}
void handler(int signum)
{
	static int decimal;
	int weight;
	static int bit;

	weight = 1;
	weight = square_dyali(weight,bit);
	if(signum == SIGUSR2)
	{
		decimal = decimal + (1 * weight);
		//ft_printf("decimal = %d\n",decimal);
	}
	bit++;
	//ft_printf("bit = %d\n",bit);
	if (bit == 7)
	{
		ft_putchar_fd(decimal, 1);
		bit = 0;
		decimal = 0;
	}
}
int main(void)
{
	ft_printf("Welcome To My Server!\n");
	ft_printf("My Server PID is: %d\n", getpid());
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while(1)
		sleep(1);
	return (0);
}
