/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 00:09:45 by lsinigag          #+#    #+#             */
/*   Updated: 2023/02/07 03:37:03 by lsinigag         ###   ########.fr       */
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

char	*ft_strrchr( char *str, int c)
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

char	*ft_strjoin(char *first, char *second)
{
	char		*str;
	long long	i;
	long long	j;

	if (!first || !second)
		return (0);
	i = 0;
	j = 0;
	str = malloc((ft_strlen(first)+ft_strlen(second)+1) * sizeof(char));
	if (!str)
		return (0);
	while (first[i])
	{
	str[i] = first[i];
	i++;
	}
	while (second[j])
	{
		str[i] = second[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(first);
	free(second);
	return (str);
}

char	*ft_substr(char *s, size_t start, size_t len)
{
	char	*ptr;
	size_t	index;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		start = ft_strlen(s);
	if ((start + len) >= ft_strlen(s))
		len = ft_strlen(s) - start;
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (ptr);
	index = 0;
	while (index != len)
	{
		ptr[index] = *(s + start + index);
		index++;
	}
	ptr[index] = '\0';
	return (ptr);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	if (!src)
		return (0);
	dest = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!dest)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
