/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoubby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:37:54 by echoubby          #+#    #+#             */
/*   Updated: 2023/11/26 19:16:06 by echoubby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr(unsigned long long n, char const *base)
{
	int						i;
	unsigned long long		base_len;

	base_len = ft_strlen(base);
	i = 0;
	if (n < base_len)
		i = ft_putchar(base[n]);
	else
	{
		i += ft_putnbr((n / base_len), base);
		i += ft_putnbr((n % base_len), base);
	}
	return (i);
}
