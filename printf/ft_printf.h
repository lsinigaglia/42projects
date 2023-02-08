/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 00:39:02 by lsinigag          #+#    #+#             */
/*   Updated: 2023/02/04 00:37:59 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_puthexl(unsigned long n, char *str);
int	ft_putnbr(int num);
int	ft_putstr(char *s);
int	ft_putchar(char c);
int	ft_puthex(unsigned int n, char *str);
int	ft_putnbr_u(unsigned int n);
int	ft_printf(const char *str, ...);

#endif
