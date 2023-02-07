/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 00:09:53 by lsinigag          #+#    #+#             */
/*   Updated: 2023/02/07 05:01:08 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "string.h"

static char	*get_the_line(int fd)
{
	char		*temp;
	static ssize_t		buff_len;
	char		buf[6];
	static char	*backup;
	static int	flag;
	int i;

	// if (read (fd, buf, 5) == 0)
	// 	return NULL;
		if (backup)
	{
		i = backup[0] + 48;
		//write(1, &i, 1);
		if ((*backup) == '\0')
		{
			// write(1, &i, 1);
			return (0);
		}
	}
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
		// printf("##\n");
		// printf("%3zi", buff_len);
		if (buff_len <= 0)
		{
			// write(1, "#\n", 2);
			*backup = '\0';
			// write(1, backup, 1);
		 	return (backup) ;
		}
		buf[buff_len] = 0;
		temp = (char *)malloc(buff_len + 1);
		temp = ft_strdup(buf);
		//temp[buff_len] = 0;
		if (!backup)
			backup = strdup("");
		backup = ft_strjoin(backup, temp);
		printf("backup:%s\n", backup);
		//printf ("%s", backup);
		// printf ("%zi", buff_len);
		if (ft_strrchr(backup, '\n') || buff_len < 5)
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
	static ssize_t		buff_len;
	int i;

	// if (*backup == '\0')
	// 	return (NULL);

	next_line = ft_strdup(get_the_line(fd));
	// printf("backup:%s\n", next_line);
	if (next_line == 0)
		return (NULL);
	i = next_line[0] + 48;
	//write(1, &i, 1);
	//printf("stringa grezza:%s\n", next_line);
	//printf("%s", next_line);

	if (ft_strrchr(next_line, '\n') != 0)
	{
		end_of_line = ft_strrchr(next_line, '\n');
		*(end_of_line + 1) = 0;
	}
	else
	{
		*((next_line) + ft_strlen(next_line) + 1) = 0;
		printf("%sASD\n", next_line);
	}
	//write(1, "+\n", 2);
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
