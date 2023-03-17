/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:32:24 by lsinigag          #+#    #+#             */
/*   Updated: 2023/03/17 01:37:52 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mandelbrot.h"

int	check_params_julia(int argc, char **argv)
{
	int	i;

	i = -1;
	while (argv[2][++i] != 0)
	{
		if ((!(argv[2][i] >= '0' && argv[2][i] <= '9')) && argv[2][i] != '.' && argv[2][i] != '-')
			return (2);
	}
	i = -1;
	while (argv[3][++i] != 0)
	{
		if ((!(argv[3][i] >= '0' && argv[3][i] <= '9'))
			&& argv[3][i] != '.' && argv[3][i] != '-')
			return (2);
	}
	return (0);
}

int	check_parameters(int argc, char **argv)
{
	int	i;
	int	res;

	i = -1;
	if (argc < 2 || argc > 4)
		return (1);
	if ((ft_strncmp(argv[1], "mandelbrot", 11) != 0)
		&& ((ft_strncmp(argv[1], "julia", 6) != 0)))
		return (1);
	if (ft_strncmp(argv[1], "mandelbrot", 11) == 0 && (argc > 2))
		return (1);
	if (ft_strncmp(argv[1], "julia", 6) == 0 && argc != 4)
		return (2);
	if (ft_strncmp(argv[1], "julia", 6) == 0)
	{
		res = check_params_julia(argc, argv);
		return (res);
	}
	return (0);
}

int	write_checks(int argc, char **argv)
{
	if (check_parameters(argc, argv) == 1)
	{
		ft_printf("Benvenuto nel magico mondo dei frattali. inserire la parola \
mandelbrot o la parola julia per i corrispondenti frattali\n");
		return (1);
	}
	if (check_parameters(argc, argv) == 2)
	{
		ft_printf("inserire i parametri per julia in questo modo \
: a.out julia x y\n");
		return (1);
	}
	return (0);
}
