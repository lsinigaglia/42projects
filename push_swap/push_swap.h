/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:02:11 by lsinigag          #+#    #+#             */
/*   Updated: 2023/03/24 21:12:55 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"

void	swap(t_list *head_A);
void	ss(t_list *head_A, t_list *head_B);
void	push(t_list *head_A, t_list *head_B);
t_list	*ft_lstsecondlast(t_list *lst);
void	rotate(t_list *head);

#endif
