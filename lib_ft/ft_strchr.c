/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:42:25 by lsinigag          #+#    #+#             */
/*   Updated: 2023/01/18 19:02:18 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strchr(const char *str, int c)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == c)
			return ((char *)(s + i));
	}
	return (0);
}