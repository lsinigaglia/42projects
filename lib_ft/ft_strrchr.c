/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:02:45 by lsinigag          #+#    #+#             */
/*   Updated: 2023/01/18 19:07:46 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strrchr(const char *str, int c)
{
	size_t	i;

	i = 1 + ft_strlen(str);
	while (i-- > 0)
	{
		if (str[i] == c)
			return ((char *)(str + i));
	}
	return (0);
}
