/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:02:07 by lsinigag          #+#    #+#             */
/*   Updated: 2023/05/24 15:55:24 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_push(t_stack **head_A, t_stack **head_B, int stack_size)
	{
	int	i;

	i = 0;
	while (stack_size > 6 && i < stack_size / 2)
	{
		if ((*head_A)->cardinal_number > stack_size / 2)
		{
			do_pb(head_A, head_B);
			i++;
		}
		else
			do_ra(head_A);
	}
	while (stack_size - i > 3)
	{
		do_pb(head_A, head_B);
		i++;
	}
}

void	final_rotate(t_stack **head_A)
{
	int	stack_size;

	stack_size = get_stack_size(*head_A);
	if (sorted_check(*head_A))
		return ;
	while ((*head_A)->cardinal_number > 1)
	{
		if ((*head_A)->cardinal_number < stack_size / 2)
			do_rra(head_A);
		else
			do_ra(head_A);
	}
}

void	lets_push_swap(t_stack **head_A, t_stack **head_B, int stack_size)
{
	big_push(head_A, head_B, stack_size);
	three_sort(head_A);
	while (*head_B)
	{
		lets_get_position(head_A, head_B);
		get_cost(head_A, head_B);
		do_cheapest_move(head_A, head_B);
	}
	final_rotate(head_A);
}
