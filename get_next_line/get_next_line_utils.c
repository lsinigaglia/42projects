/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 00:09:45 by lsinigag          #+#    #+#             */
/*   Updated: 2023/02/10 05:44:09 by lsinigag         ###   ########.fr       */
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

char	*ft_strchr( char *str, int c)
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

char	*ft_strjoin(char *raw_string, char *second)
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
	i = 0;
	j = 0;
	str = malloc((ft_strlen(raw_string)+ft_strlen(second)+1) * sizeof(char));
	if (!str)
		return (NULL);
	while (raw_string[i])
	{
	str[i] = raw_string[i];
	i++;
	}
	while (second[j])
		str[i++] = second[j++];
	str[i] = '\0';
	free(raw_string);
	return (str);
}
