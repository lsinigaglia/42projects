/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 00:09:45 by lsinigag          #+#    #+#             */
/*   Updated: 2023/02/13 01:53:54 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen1(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr1( char *str, int c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}

char	*ft_strjoin1(char *raw_string, char *second)
{
	char		*str;
	long long	i;
	long long	j;

	if (!raw_string)
	{
		raw_string = (char *)malloc(1);
		raw_string[0] = 0;
	}
	if (!raw_string || !second)
		return (NULL);
	i = -1;
	j = 0;
	str = malloc((ft_strlen1(raw_string)+ft_strlen1(second)+1) * sizeof(char));
	if (!str)
		return (NULL);
	while (raw_string[++i])
		str[i] = raw_string[i];
	while (second[j])
		str[i++] = second[j++];
	str[i] = '\0';
	free(raw_string);
	return (str);
}

char	*ft_strdup1(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char *)malloc(sizeof(char) * ft_strlen1(src) + 1);
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
