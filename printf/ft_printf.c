/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:09:32 by lsinigag          #+#    #+#             */
/*   Updated: 2023/02/01 02:32:54 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

static int	specifire(va_list *args, char c)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += ft_putchar(va_arg(*args, int));
	else if (c == 'd' || c == 'i')
		i += ft_putnbr(va_arg(*args, int));
	else if (c == 's')
		i += ft_putstr(va_arg(*args, char *));
	else if (c == 'p')
	{
		i += write(1, "0x", 2);
		i += ft_puthexl(va_arg(*args, unsigned long),
				"0123456789abcdef");
	}
	else if (c == 'u')
		i += ft_putnbr_u(va_arg(*args, unsigned int));
	else if (c == 'x')
		i += ft_puthex(va_arg(*args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
	{
		i += ft_puthexl(va_arg(*args, unsigned long),
				"0123456789ABCDEF");
	}
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		fire;
	va_list	args;

	i = 0;
	fire = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '%')
			{
				fire += ft_putchar('%');
				i++;
			}
			else
			{
				fire += specifire(&args, str[i]);
				i++;
			}
		}
		if (str[i] != '%' && str[i])
		{
			fire += ft_putchar(str[i]);
			i++;
		}
	}
	va_end(args);
	return (fire);
}
