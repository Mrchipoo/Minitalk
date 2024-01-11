/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoubby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:34:13 by echoubby          #+#    #+#             */
/*   Updated: 2024/01/11 09:44:28 by echoubby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_git/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

int	ft_isdigit(char *c);

int	ft_atoi(const char *nptr);

void	handler(int pid, char msg)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((msg & (1 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(350);
		bit++;
	}
}

int	stupid_client(int argc, char **av)
{
	int	num;

	num = 0;
	if (argc != 3)
	{
		ft_printf("program need 2 arguments to work");
		return (num);
	}
	if (ft_isdigit(av[1]) == 0)
	{
		ft_printf("server Pid should contain only numbers\n");
		return (num);
	}
	if (*av[2] == 0)
	{
		ft_printf("message can not be empty\n");
		return (num);
	}
	num = 1;
	return (num);
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;
	char	*msg;

	i = 0;
	if (stupid_client(argc, argv) == 1)
	{
		pid = ft_atoi(argv[1]);
		msg = argv[2];
		while (msg[i] != '\0')
		{
			handler(pid, msg[i]);
			i++;
        	}
		handler(pid, '\n');
	}
	return (0);
}
