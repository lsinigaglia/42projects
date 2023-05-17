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

void get_pos(the_stack **head_A)
{
    the_stack *temp;
    int i;

    i = 0;
    temp = *head_A;
    while (temp)
    {
        temp->position = i;
        i++;
        temp = temp->next;
    }
}

int get_target_min(the_stack **head_A)
{
    the_stack *temp;
    int tar_number;
    int target_position;

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

int get_target_pos(the_stack **head_A, int b_card)
{
	the_stack *temp;
	int target_pos;
	int A_limit;

	target_pos = 0;
	A_limit = 2147483647;
	temp = *head_A;
	while (temp)	
	{
		if (b_card < temp->cardinal_number && temp->cardinal_number < A_limit)
		{
			target_pos = temp->position;
			A_limit = temp->cardinal_number; 
		}
		temp = temp->next;
	}
	if (A_limit != 2147483647)
		return (target_pos);

	target_pos = get_target_min(head_A);
	return (target_pos);
}

void    lets_get_position(the_stack **head_A, the_stack **head_B)
{
	the_stack *temp_B;

	temp_B = *head_B;
	while (temp_B)
	{
		get_pos(head_A);
		get_pos(head_B);
		temp_B->target_pos = get_target_pos(head_A, temp_B->cardinal_number);
		temp_B = temp_B->next;
	}
}