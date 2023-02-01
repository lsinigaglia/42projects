/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MAIN.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 00:58:33 by lsinigag          #+#    #+#             */
/*   Updated: 2023/02/01 02:40:30 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

int main()
{
	char	c = '!';
	int		i = 42;
	char s[] = "CIAO";
	void *ptr;
	ptr = &c;
	unsigned int num = 123123;
	int esa = 16;
	int ESA = 15;

	//ft_printf("int: %i\nchar: %s%s\npointer: %p\nstring: %c\nunsigned int: %u\n", i, "hello", s, ptr, c, num);
	ft_printf("%i\n", ft_printf("%x\n%X\n%%\n", esa, ESA));
}
