/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MAIN.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:01:10 by lsinigag          #+#    #+#             */
/*   Updated: 2023/01/21 18:21:14 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	main (int argc, char** argv)
{
	printf ("%s\n", ft_strnstr(argv[1], argv[2], 15));
}
