/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoubby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:04:15 by echoubby          #+#    #+#             */
/*   Updated: 2024/05/10 19:13:03 by echoubby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar_fd(char c, int fd);

void	ft_putnbr(unsigned long long n)
{
	unsigned long long	base_len;
	char				*s;

	s = "0123456789";
	base_len = 10;
	if (n < base_len)
		ft_putchar_fd(s[n], 1);
	else
	{
		ft_putnbr((n / base_len));
		ft_putnbr((n % base_len));
	}
}
