/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheap_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:44:15 by lsinigag          #+#    #+#             */
/*   Updated: 2023/05/24 16:18:02 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	abs(int number)
{
	if (number < 0)
		number = -number;
	return (number);
}

void	get_cost(t_stack **head_a, t_stack **head_b)
{
	t_stack	*temp_b;
	int		size_stack_b;
	int		size_stack_a;

	temp_b = *head_b;
	size_stack_a = get_stack_size(*head_a);
	size_stack_b = get_stack_size(*head_b);
	while (temp_b)
	{
		temp_b->cost_b = temp_b->position;
		temp_b->cost_a = temp_b->target_pos;
		if (temp_b->cost_b > (size_stack_b / 2))
			temp_b->cost_b = -(size_stack_b - temp_b->position);
		if (temp_b->cost_a > (size_stack_a / 2))
			temp_b->cost_a = -(size_stack_a - temp_b->target_pos);
		temp_b = temp_b->next;
	}
}

void	the_move(t_stack **head_a, t_stack **head_b, int a, int b)
{
	while (a < 0 && b < 0)
	{
		do_rrr(head_a, head_b);
		a++;
		b++;
	}
	while (a > 0 && b > 0)
	{
		do_rr(head_a, head_b);
		a--;
		b--;
	}
	while (a > 0)
	{
		do_ra(head_a);
		a--;
	}
	while (a < 0)
	{
		do_rra(head_a);
		a++;
	}
	the_move_help(head_b, &b);
	do_pa(head_a, head_b);
}

void	the_move_help(t_stack **head_b, int *b)
{
	while (*b > 0)
	{
		do_rb(head_b);
		(*b)--;
	}
	while (b < 0)
	{
		do_rrb(head_b);
		(*b)++;
	}
}

void	do_cheapest_move(t_stack **head_a, t_stack **head_b)
{
	t_stack	*temp;
	int		final_a;
	int		final_b;
	int		cheapest;

	cheapest = 2147483647;
	temp = (*head_b);
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
	the_move(head_a, head_b, final_a, final_b);
}
