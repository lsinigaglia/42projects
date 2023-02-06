/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 00:09:53 by lsinigag          #+#    #+#             */
/*   Updated: 2023/02/06 03:57:53 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "string.h"

static char	*get_the_line(int fd)
{
	char		*temp;
	ssize_t		buff_len;
	char		buf[6];
	static char	*backup;
	static int	flag;

	if (backup)
	{
		temp = backup;
		backup = ft_strdup(ft_strrchr(temp, '\n') + 1);
		free (temp);
	}
	if (!backup)
		backup = strdup("");
	flag = 0;
	//printf("##\n");
	while (flag == 0)
	{
		buff_len = read(fd, buf, 5);
		printf("##\n");
		if (buff_len == 0)
		{
			printf("buff_len:%zi", buff_len);
			flag = 1;
		 	break ;
		}
		buf[buff_len] = 0;
		temp = (char *)malloc(buff_len + 1);
		temp = ft_strdup(buf);
		temp[buff_len] = 0;
		backup = ft_strjoin(backup, temp);
		if (ft_strrchr(backup, '\n'))
			break ;
		// if (buff_len < 5)
		// 	break ;
	}
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*next_line;
	static char	*backup;
	char		*end_of_line;
	static int	flag;

	if (flag == 1)
		return (NULL);
	next_line = strdup(get_the_line(fd));
	if (ft_strrchr(next_line, '\n') != 0)
	{
		end_of_line = ft_strrchr(next_line, '\n');
		*(end_of_line + 1) = 0;
	}
	else
		next_line[ft_strlen(next_line)] = 0;
	return (next_line);
}

char	*extract(char *str)
{
	char	*new_line;
	char	*the_sub_string;

	new_line = ft_strrchr(str, '\n');
	the_sub_string = ft_substr(new_line, 0, 5);
	return (str);
}
