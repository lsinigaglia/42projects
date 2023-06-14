/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_positions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:44:15 by lsinigag          #+#    #+#             */
/*   Updated: 2023/05/24 15:59:48 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_pos(t_stack **head_A)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = *head_A;
	while (temp)
	{
		temp->position = i;
		i++;
		temp = temp->next;
	}
}

int	get_target_min(t_stack **head_A)
{
	t_stack	*temp;
	int		tar_number;
	int		target_position;

	temp = *head_A;
	target_position = 0;
	tar_number = 2147483647;
	while (temp)
	{
		if (tar_number > temp->cardinal_number)
		{
			tar_number = temp->cardinal_number;
			target_position = temp->position;
		}
		temp = temp->next;
	}
	return (target_position);
}

int	get_target_pos(t_stack **head_a, int b_card)
{
	t_stack	*temp;
	int		target_pos;
	int		a_limit;

	target_pos = 0;
	a_limit = 2147483647;
	temp = *head_a;
	while (temp)
	{
		if (b_card < temp->cardinal_number && temp->cardinal_number < a_limit)
		{
			target_pos = temp->position;
			a_limit = temp->cardinal_number;
		}
		temp = temp->next;
	}
	if (a_limit != 2147483647)
		return (target_pos);
	target_pos = get_target_min(head_a);
	return (target_pos);
}

void	lets_get_position(t_stack **head_A, t_stack **head_b)
{
	t_stack	*temp_b;

	temp_b = *head_b;
	while (temp_b)
	{
		get_pos(head_A);
		get_pos(head_b);
		temp_b->target_pos = get_target_pos(head_A, temp_b->cardinal_number);
		temp_b = temp_b->next;
	}
}
