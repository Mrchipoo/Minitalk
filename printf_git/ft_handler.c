/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoubby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:28:22 by echoubby          #+#    #+#             */
/*   Updated: 2023/12/01 10:29:29 by echoubby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_hexlower(va_list ptr)
{
	unsigned int	nbr;

	nbr = va_arg(ptr, unsigned int);
	return (ft_putnbr(nbr, "0123456789abcdef"));
}

int	ft_hexupper(va_list ptr)
{
	unsigned int	nbr;

	nbr = va_arg(ptr, unsigned int);
	return (ft_putnbr(nbr, "0123456789ABCDEF"));
}

int	ft_int(va_list ptr)
{
	long long	nbr;

	nbr = va_arg(ptr, int);
	if (nbr < 0)
	{
		write(1, "-", 1);
		return (ft_putnbr(-nbr, "0123456789") + 1);
	}
	return (ft_putnbr(nbr, "0123456789"));
}

int	ft_unsigned_int(va_list ptr)
{
	unsigned int	nbr;

	nbr = va_arg(ptr, unsigned int);
	return (ft_putnbr(nbr, "0123456789"));
}

int	ft_pointer(va_list ptr)
{
	void	*nbr;

	nbr = va_arg(ptr, void *);
	if (nbr == NULL)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	return (ft_putnbr((unsigned long long)nbr, "0123456789abcdef") + 2);
}
