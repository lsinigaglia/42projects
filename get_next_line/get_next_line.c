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

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*true_string;

	while (read(fd, *buffer, BUFFER_SIZE) > 0)
	{

	}
}
static char *get_the_line(int fd,char *buf)
{
	static char *the_line;
	char 		*temp;
	int			buff_len;
	int			flag;


	flag = 0;

	while (flag = 0)
	{
		buff_len = read(fd, buf, BUFFER_SIZE);
		temp = (char *)malloc(BUFFER_SIZE + 1);
		the_line[buff_len] = 0;
		temp = buf;
		the_line = strjoin(the_line, temp);
		free (temp);
		if (strrchar(the_line, '\n'))
		{
			the_line[strrchar(the_line, '\n') + 1] = 0;
			break;
		}
		if (buff_len == 0)
			flag = 1;
	}
		return (the_line);
}
