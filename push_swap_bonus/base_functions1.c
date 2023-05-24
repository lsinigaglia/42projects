/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_functions1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:35:40 by lsinigag          #+#    #+#             */
/*   Updated: 2023/05/24 16:37:20 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	do_rrr(t_stack **heada, t_stack **headb)
{
	reverse_rotate(heada);
	reverse_rotate(headb);
}

/* the first element becomes the last one */
void	rotate(t_stack **head)
{
	t_stack	*last;
	t_stack	*original_head;

	if (!head || !*head || !(*head)->next)
		return ;
	original_head = (*head);
	last = get_last_stack(*head);
	last->next = original_head;
	original_head->next = NULL;
}

void	do_ra(t_stack **head)
{
	rotate(head);
	ft_printf("ra\n");
}

void	do_rb(t_stack **head)
{
	rotate(head);
	ft_printf("rb\n");
}

void	do_rr(t_stack **heada, t_stack **headb)
{
	rotate(heada);
	rotate(headb);
}
