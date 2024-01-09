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

void handler(int signum)
{
	static int decimal;
	static int weight;
	int bit;

	bit = 7;
	weight = 1;
	decimal = 0;
	while (bit > 0)
	{
		if(signum == SIGUSR2)
		{
			decimal = decimal + weight;
			printf("decimal = %d\n",decimal);
		}
		else if (signum == SIGUSR1)
			//printf("decimal2 = %d\n",decimal);
		weight = weight * 2;
		printf("signum = %d\n",signum);
		bit--;
	}
	printf("%c",decimal);
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
