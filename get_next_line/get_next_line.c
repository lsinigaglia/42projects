/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 00:09:53 by lsinigag          #+#    #+#             */
/*   Updated: 2023/02/08 17:13:11 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
