/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 00:09:43 by lsinigag          #+#    #+#             */
/*   Updated: 2023/02/02 02:58:43 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "string.h"

/*char	*get_next_line(int fd)
{
	char		*buffer;
	char	*true_string;

	while (read(fd, *buffer, BUFFER_SIZE) > 0)
	{

	}
}*/
char *get_the_line(int fd,char *buf)
{
	char *the_line;
	char 		*temp;
	ssize_t		buff_len;
	int			flag;
	char 		*new_line;


	the_line = strdup ("");
	flag = 0;

	while (flag == 0)
	{
		buff_len = read(fd, buf, 10);
		//printf ("%li\n", buff_len);
		temp = (char *)malloc(10 + 1);
		temp = strdup(buf);
		temp[buff_len] = 0;
		//printf ("%s\n", temp);
		
		the_line = ft_strjoin(the_line, temp);
		//printf ("strjoin: %s\n", the_line);
		free (temp);
		if (ft_strrchr(the_line, '\n'))
		{
			new_line = ft_strrchr(the_line, '\n');
			printf ("%s\n", new_line);
			new_line [10] = 0;
			break;
		}
		if (buff_len == 0)
			flag = 1;
	}
		return (the_line);
}
