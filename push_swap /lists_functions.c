/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:02:08 by lsinigag          #+#    #+#             */
/*   Updated: 2023/05/24 15:56:34 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_last_stack(t_stack *head)
{
	while (head->next)
		head = head->next;
	return (head);
}

t_stack	*get_second_last_stack(t_stack *head)
{
	while (head->next->next)
		head = head->next;
	return (head);
}

t_stack	*ft_lstmake(int number)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->original_number = number;
	new->cardinal_number = 0;
	new->position = -1;
	new->target_pos = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

void	ft_add_to_last(t_stack **head, t_stack *new)
{
	t_stack	*last;

	if (!new)
		return ;
	if (!*head)
	{
		*head = new;
		return ;
	}
	last = get_last_stack(*head);
	last->next = new;
	return ;
}
