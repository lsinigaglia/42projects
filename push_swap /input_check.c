/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:02:07 by lsinigag          #+#    #+#             */
/*   Updated: 2023/04/24 23:50:09 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strncmp_pl(char *ptr1, char *ptr2, size_t n)
{
	unsigned int	i;
	unsigned int	j;


	j = 0;
	i = 0;
	if (ptr1[i] == '+')
		i++;
	if (ptr2[j] == '+')
		j++;

	while ((ptr1[i] != '\0' || ptr2[j] != '\0') && i < n)
	{
		if (ptr1[i] > ptr2[j])
		{
			return (1);
		}
		else if (ptr1[i] < ptr2[j])
		{
			return (-1);
		}
		i++;
	}
	return (0);
}

int not_number_found(char *s)
{
	int	i;
	int	sign;

	sign = 0;
	i = 0;
	if (!s)
		return (1);
	if ((s[i] == '+' || s[i] == '-'))
		i++;
	if (s[i] == 0)
		return (1);
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int duplicate_found(char **argv)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (argv[++i])
	{
		j = i;
		while (argv[++j])
		{
			if (ft_strncmp_pl(argv[i], argv[j], (ft_strlen(argv[i]) + 1)) == 0)
				return (1);
		}
	}
	return (0);
}

int	wrong_zero_yes(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (argv[i][0] == '0' && argv[i][1] == '0')
			return (1);
	}
	return (0);

}
int	are_you_sure_about_the_input(char **argv)
{
    int i;

	i = 1;
	
	while (argv[i])
	{
		if (not_number_found(argv[i]))
			return (0);
		i++;
	}
	if (duplicate_found(argv))
		return (0);
	if (wrong_zero_yes(argv))
	 	return (0);

    return (1);
}