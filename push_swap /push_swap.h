/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:02:11 by lsinigag          #+#    #+#             */
/*   Updated: 2023/04/25 01:40:26 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"

typedef	struct s_list
{
	int	size_a;
	int	size_b;
}
void	swap(t_list **head_A);
void	push(t_list **head_A, t_list **head_B);
t_list	*ft_lstsecondlast(t_list *lst);
void	rotate(t_list **head);
void	reverse_rotate(t_list **head);
int		ftcheck_atoi(const char *str);
void	rr(t_list **head_A, t_list **head_B);
void	rra(t_list **head_A, t_list **head_B);
void	ss(t_list **head_A, t_list **head_B);
void	print_list_contents(t_list *head);
void	free_stack(t_list **stack);

#endif
