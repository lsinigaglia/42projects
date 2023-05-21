/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:02:07 by lsinigag          #+#    #+#             */
/*   Updated: 2023/04/24 23:50:09 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(t_stack **head_A)
{
	t_stack *temp;

	if (head_A == NULL || (*head_A)->next == NULL || (*head_A) == NULL)
		return ;
	temp = *head_A;
	(*head_A) = (*head_A)->next;
	temp->next = (*head_A)->next;
	(*head_A)->next = temp;
}
void	do_sa(t_stack **head)
{
	swap(head);
	ft_printf("sa\n");
}

void	do_sb(t_stack **head)
{
	swap(head);
	ft_printf("sb\n");
}

void	ss(t_stack **headA, t_stack **headB)
{
	swap(headA);
	swap(headB);
}

void	push(t_stack **head_A, t_stack **head_B)
{
	t_stack *tmp;

	if (head_A == NULL)
		return;
	tmp = (*head_A)->next;

	(*head_A)->next = (*head_B);
	*head_B = *head_A;
	*head_A = tmp;
}

void	do_pa(t_stack **head_A, t_stack **head_B)
{
	push(head_B, head_A);
	ft_putstr("pa\n");
}

void	do_pb(t_stack **head_A, t_stack **head_B)
{
	push(head_A, head_B);
	ft_putstr("pb\n");
}
/* the last element becomes the first one */
void	reverse_rotate(t_stack **head)
{
	t_stack *last;
	t_stack *second_last;

	if (!head || !*head || !(*head)->next) // Check if the list is empty or has only one element
		return;

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

void	do_rrr(t_stack **headA, t_stack **headB)
{
	reverse_rotate(headA);
	reverse_rotate(headB);
}
/* the first element becomes the last one */
void rotate(t_stack **head)
{
	t_stack *last;
	t_stack *original_head;

	if (!head || !*head || !(*head)->next) 
		return;

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

void	do_rr(t_stack **headA, t_stack **headB)
{
	rotate(headA);
	rotate(headB);
}