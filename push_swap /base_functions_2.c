/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:05:45 by lsinigag          #+#    #+#             */
/*   Updated: 2023/05/24 16:07:38 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_pa(t_stack **head_a, t_stack **head_b)
{
	push(head_b, head_a);
	ft_putstr("pa\n");
}

void	do_pb(t_stack **head_a, t_stack **head_b)
{
	push(head_a, head_b);
	ft_putstr("pb\n");
}

/* the last element becomes the first one */
void	reverse_rotate(t_stack **head)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!head || !*head || !(*head)->next)
		return ;
	last = get_last_stack(*head);
	second_last = get_second_last_stack(*head);
	second_last->next = NULL;
	last->next = (*head);
	(*head) = last;
}

void	do_rra(t_stack **head)
{
	reverse_rotate(head);
	ft_printf("rra\n");
}

void	do_rrb(t_stack **head)
{
	reverse_rotate(head);
	ft_printf("rrb\n");
}
