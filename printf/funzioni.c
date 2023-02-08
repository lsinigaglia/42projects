/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funzioni.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 22:28:55 by lsinigag          #+#    #+#             */
/*   Updated: 2023/02/04 00:19:04 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(int num)
{
	int		i;
	long	nb;

	nb = num;
	i = 0;
	if (nb < 0)
	{
		i += ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
		i += ft_putnbr(nb / 10);
	i += ft_putchar(nb % 10 + 48);
	return (i);
}

int	ft_puthexl(unsigned long n, char *str)
{
	int		i;

	i = 0;
	if (n >= 16)
		i += ft_puthexl(n / 16, str);
	i += ft_putchar(str[n % 16]);
	return (i);
}
