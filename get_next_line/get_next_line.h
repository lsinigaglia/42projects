/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 00:09:48 by lsinigag          #+#    #+#             */
/*   Updated: 2023/02/02 00:09:49 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
# include <fcntl.h>


char        *get_the_line(int fd,char *buf);
char	    *ft_strjoin(char *first, char *second);
int         ft_strlen(char *str);
char	    *ft_strrchr(const char *str, int c);

#endif
