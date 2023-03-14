#include <math.h>
#include <stdio.h>
#include "Mandelbrot.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
double	ft_atof(char *str)
{
	int		i;
	int		sign;
	double	res;
	int		floater;

	i = 0;
	sign = 1;
	res = 0;
	floater = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == 32)
		i++;
	if (str[i] == '+')
			i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
	{
		res = str[i] - 48 + (res * 10);
		i++;
		if (str[i] == '.')
		{
			floater = 10;
			floater = pow(floater, (ft_strlen(str + i) - 1));
			i++;
		}
	}
	res *= (double)1/floater;
	return (res * sign);
}

int	main()
{
	double x;
	char *str = "1234.5";
	x = ft_atof(str);
	printf ("RISULTATO:%f\n", x);
}




// typedef struct	s_cmp{
// 	double	real;
// 	double	imag;
// }				t_cmp;

// int main ()
// {
// 	t_cmp z;
// 	t_cmp c;
// 	double temp;
// 	int i;
// 	z.real = 3.0;
// 	z.imag = 4.0;
// 	c.real = 0;
// 	c.imag = 0;
// 	temp = z.real;
// 	while (i++ < 2)
// 	{
// 		z.real = ((z.real) * (z.real)) - (z.imag * z.imag) + c.real;
// 		z.imag = 2 * (temp * z.imag) + c.imag;
// 		printf("z.real : %f\nz.imag: %f\n", z.real, z.imag);
// 	}
// }

// while (i++ < 1000)
// 		{
// 			temp = z.real;
// 			z.real = (z.real) * (z.real) - (z.imag * z.imag) + c.real;
// 			z.imag = 2 * (temp * z.imag) + c.imag;
// 			// printf("z.real : %f\nz.imag: %f\n", z.real, z.imag);
// 			// printf("%i Z value: %f\n", i, creal(z));
// 			if (sqrt(fabs(z.real) + fabs(z.imag)) >= 2)
// 				return (i);
// 		}
