/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_functions_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:03:53 by lsinigag          #+#    #+#             */
/*   Updated: 2023/05/24 16:04:56 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rrr(t_stack **heada, t_stack **headb)
{
	reverse_rotate(heada);
	reverse_rotate(headb);
	ft_printf("rrr\n");
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
	(*head) = (*head)->next;
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
	ft_printf("rr\n");
}
