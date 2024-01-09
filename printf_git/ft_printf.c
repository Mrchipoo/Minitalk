/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoubby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:21:04 by echoubby          #+#    #+#             */
/*   Updated: 2023/12/01 10:32:37 by echoubby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int	ft_putchar(int c)
{
	int	i;

	i = 0;
	i = write(1, &c, 1);
	return (i);
}

int	ft_checker(char spec, va_list ptr)
{
	int	i;

	i = 0;
	if (spec == 'c')
		i = ft_putchar(va_arg(ptr, int));
	else if (spec == 's')
		i = ft_putstr(va_arg(ptr, char *));
	else if (spec == 'd' || spec == 'i')
		i = ft_int(ptr);
	else if (spec == 'x')
		i = ft_hexlower(ptr);
	else if (spec == 'X')
		i = ft_hexupper(ptr);
	else if (spec == 'u')
		i = ft_unsigned_int(ptr);
	else if (spec == 'p')
		i = ft_pointer(ptr);
	else
		i = write(1, &spec, 1);
	return (i);
}

int	ft_printf(const char *kalma, ...)
{
	va_list	ptr;
	int		i;

	i = 0;
	if (kalma == NULL)
		return (-1);
	va_start(ptr, kalma);
	while (*kalma)
	{
		if (*kalma == '%' && *kalma + 1 != '\0')
			i += ft_checker(*(++kalma), ptr);
		else
			i += write(1, kalma, 1);
		kalma++;
	}
	va_end(ptr);
	return (i);
}
