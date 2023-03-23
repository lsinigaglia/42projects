/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:32:24 by lsinigag          #+#    #+#             */
/*   Updated: 2023/03/23 18:49:43 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mandelbrot.h"

int	check_params_julia(int argc, char **argv)
{
	int	i;

	i = -1;
	while (argv[2][++i] != 0)
	{
		if ((!(argv[2][i] >= '0' && argv[2][i] <= '9')) && argv[2][i]
			!= '.' && argv[2][i] != '-')
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
		&& ((ft_strncmp(argv[1], "julia", 6) != 0))
		&& ft_strncmp(argv[1], "newton", 7) != 0)
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
	if (ft_strncmp(argv[1], "newton", 7) == 0)
		return (3);
	return (0);
}

int	write_checks(int argc, char **argv)
{
	if (check_parameters(argc, argv) == 1)
	{
		ft_printf("Welcome to the magical world of fractals. Enter the word mandelbrot, \
julia or newton for the corresponding fractal. \n");
		return (1);
	}
	if (check_parameters(argc, argv) == 2)
	{
		ft_printf("insert the julia parameters this way: fractal julia x y\n\
these are some very cool values!\
Douady's Rabbit: -0.123 0.745\nSan Marco Fractal: -0.75\nSeahorse Valley: -0.75 0.15\n\
Whisker Valley: -0.8 0.156\nGalactic Fractal: -0.391 -0.587\n\
Dragon Fractal: 0.45 -0.1428\nSatellite Antenna Fractal: 0.110 0.670\n");
		return (1);
	}
	return (0);
}
