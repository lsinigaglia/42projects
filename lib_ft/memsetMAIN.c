/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memsetMAIN.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:22:43 by lsinigag          #+#    #+#             */
/*   Updated: 2023/01/17 18:25:48 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned int	i;
	char			*p;

	i = 0;
	p = str;
	while (i < n)
	{
		p[i++] = c;
	}
	return (str);
}

int	main(void)
{
	char	stringa[] = "ciao_zio_frank";
	ft_memset (stringa+5, '#', 5*sizeof(char));
	printf ("%s", stringa);
}
