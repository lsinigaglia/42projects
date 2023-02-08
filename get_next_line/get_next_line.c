/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 00:09:43 by lsinigag          #+#    #+#             */
/*   Updated: 2023/02/04 01:50:33 by lsinigag         ###   ########.fr       */
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
