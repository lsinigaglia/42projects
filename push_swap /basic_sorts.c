/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:44:15 by lsinigag          #+#    #+#             */
/*   Updated: 2023/05/24 16:01:08 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted_check(t_stack *head_A)
{
	while (head_A->next)
	{
		if (head_A->cardinal_number > head_A->next->cardinal_number)
			return (0);
		head_A = head_A->next;
	}
	return (1);
}

void	three_sort(t_stack **head_A)
{
	if (sorted_check(*head_A))
		return ;
	if ((*head_A)->cardinal_number == 3)
		do_ra(head_A);
	if ((*head_A)->next->cardinal_number == 3)
		do_rra(head_A);
	if (sorted_check(*head_A))
		return ;
	do_sa(head_A);
}

void	do_push_swap(t_stack **head_A, t_stack **head_B, int stack_size)
{
	if (stack_size == 2 && !sorted_check(*head_A))
		do_sa(head_A);
	else if (stack_size == 3)
		three_sort(head_A);
	else if (stack_size > 3 && !sorted_check(*head_A))
		lets_push_swap(head_A, head_B, stack_size);
}
