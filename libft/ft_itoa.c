/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 21:01:51 by lsinigag          #+#    #+#             */
/*   Updated: 2023/01/21 21:40:59 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	lenght_string(int n)
{
	long int	number;
	int		len;

	number = n;
	len = 1;
	if (number < 0)
	{
		len++;
		number = - number;
	}
	while (number >= 10)
	{
		number = number / 10;
		len++;
	}
	printf("%d\n", len);
	return (len);
}

char	*ft_itoa(int n)
{
	char	*stringa;
	size_t	i;
	long	number;
	size_t	len;

	len = lenght_string(n);
	number = n;
	i = 0;
	stringa = (char *)malloc(len + 1);
	if (number < 0)
	{
		number = - number;
		stringa[i++] = '-';
	}
	while (number >= 10)
	{
		stringa[len] = 48 + (number % 10);
		number /= 10;
		printf("%c", stringa[len]);
		len--;
	}
	if (number > 0 && number < 10)
	{
		printf("numero%ld", number);
		stringa[len] = 48 + (number % 10);
		printf("dopo%c", stringa[len]);
	}
	return (stringa);
}
