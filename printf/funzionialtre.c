/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funzionialtre.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 23:49:18 by lsinigag          #+#    #+#             */
/*   Updated: 2023/02/01 02:40:17 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

int	ft_putnbr_u(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 10)
		i += ft_putnbr_u(n / 10);
	i += ft_putchar(n % 10 + 48);
	return (1);
}

int	ft_puthex(unsigned int n, char *str)
{
	int		i;

	i = 0;
	if (n >= 16)
		i += ft_puthex(n / 16, str);
	i += ft_putchar(str[n % 16]);
	return (i);
}
