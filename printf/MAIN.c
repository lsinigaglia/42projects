/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MAIN.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 00:58:33 by lsinigag          #+#    #+#             */
/*   Updated: 2023/02/08 16:40:18 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
	// char	c = '!';
	// int		i = 42;
	// char s[] = "CIAO";
	// void *ptr;
	// ptr = &c;
	char s[100] = "ciao%";
	// int esa = 16;
	// int ESA = 15;

	//ft_printf("int: %i\nchar: %s%s\npointer: %p\nstring: %c\nunsigned int: %u\n", i, "hello", s, ptr, c, num);
	// ft_printf("%i\n", ft_printf("%u\n", num));
	ft_printf("%s\n", s);
}
