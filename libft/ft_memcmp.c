/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:23:47 by lsinigag          #+#    #+#             */
/*   Updated: 2023/01/20 20:40:03 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*stringa1;
	unsigned char	*stringa2;

	stringa1 = (unsigned char *)s1;
	stringa2 = (unsigned char *)s2;
	i = 0;
	while (i <= n)
	{
		if (stringa1[i] != stringa2[i])
			return (stringa1[i] - stringa2[i]);
		i++;
	}
	return (0);
}
