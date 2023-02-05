/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 00:09:45 by lsinigag          #+#    #+#             */
/*   Updated: 2023/02/02 00:09:46 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;

	i = 1 + ft_strlen((char *)str);
	while (i-- > 0)
	{
		if (str[i] == (char)c)
			return ((char *)(str + i));
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	    *str;
	long long	i;
	long long	j;

	if (!s1 || !s2)
		return (0);
	
	i = 0;
    j = 0;
	str = malloc((ft_strlen(s1)+ft_strlen(s2)+1) * sizeof(char));
	if (!str)
		return (0);
	while (s1[i])
	{
	str[i] = s1[i];
	i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

