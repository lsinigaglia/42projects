/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:02:07 by lsinigag          #+#    #+#             */
/*   Updated: 2023/05/24 16:07:21 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **head_a)
{
	t_stack	*temp;

	if (head_a == NULL || (*head_a)->next == NULL || (*head_a) == NULL)
		return ;
	temp = *head_a;
	(*head_a) = (*head_a)->next;
	temp->next = (*head_a)->next;
	(*head_a)->next = temp;
}

void	do_sa(t_stack **head)
{
	swap(head);
	ft_printf("sa\n");
}

void	do_sb(t_stack **head)
{
	swap(head);
	ft_printf("sb\n");
}

void	do_ss(t_stack **heada, t_stack **headb)
{
	swap(heada);
	swap(headb);
	ft_printf("ss\n");
}

void	push(t_stack **head_a, t_stack **head_b)
{
	t_stack	*tmp;

	if (head_a == NULL)
		return ;
	tmp = (*head_a)->next;
	(*head_a)->next = (*head_b);
	*head_b = *head_a;
	*head_a = tmp;
}
