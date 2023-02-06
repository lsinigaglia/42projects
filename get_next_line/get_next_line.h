/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 00:09:48 by lsinigag          #+#    #+#             */
/*   Updated: 2023/02/05 23:38:41 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
# include <fcntl.h>

char		*ft_strdup(char *src);
char		*get_next_line(int fd);
char		*ft_substr(char *s, size_t start, size_t len);
static char	*get_the_line(int fd);
char		*ft_strjoin(char *first, char *second);
int			ft_strlen(char *str);
char		*ft_strrchr(char *str, int c);

#endif
