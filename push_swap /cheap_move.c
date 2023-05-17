/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PROVEmain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:44:15 by lsinigag          #+#    #+#             */
/*   Updated: 2023/04/25 00:40:51 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	abs(int number)
{
	if (number < 0)
		number = -number;
	return (number);
}

void	get_cost(the_stack **head_A, the_stack **head_B)
{
	the_stack   *temp_B;
	int         size_stack_B;
	int			size_stack_A;

	temp_B = *head_B;
	size_stack_A = get_stack_size(*head_A);
	size_stack_B = get_stack_size(*head_B);
	while (temp_B)
	{
		temp_B->cost_b = temp_B->position;
		temp_B->cost_a = temp_B->target_pos;
		if (temp_B->cost_b > (size_stack_B / 2))
			temp_B->cost_b = -(size_stack_B - temp_B->position);
		if (temp_B->cost_a > (size_stack_A / 2))
			temp_B->cost_a = -(size_stack_A - temp_B->target_pos);
		temp_B = temp_B->next;
    }
}

void	the_move(the_stack **head_A, the_stack **head_B, int a, int b)
{
	while (a < 0 && b < 0)
	{
		do_rrr(head_A, head_B);
		a++;
		b++;
	}
	while (a > 0 && b > 0)
	{
		do_rr(head_A, head_B);
		a--;
		b--;
	}
	while (a > 0)
	{
		do_ra(head_A);
		a--;
	}
		
	while (a < 0)
	{
		do_rra(head_A);
		a++;
	}
	while (b > 0)
	{
		do_rb(head_B);
		b--;
	}
	while (b < 0)
	{
		do_rrb(head_B);
		b++;
	}
	do_pa(head_A, head_B);
}

void	do_cheapest_move(the_stack **head_A, the_stack **head_B)
{
	the_stack	*temp;
	int			final_a;
	int			final_b;
	int			cheapest;

	cheapest = 2147483647;
	temp = (*head_B);
	while (temp)
	{
		if (abs(temp->cost_a) + abs(temp->cost_b) < abs(cheapest))
		{
			cheapest = abs(temp->cost_a) + abs(temp->cost_b);
			final_a = temp->cost_a;
			final_b = temp->cost_b;
		}
		temp = temp->next;
	}
	the_move(head_A, head_B, final_a, final_b);
}