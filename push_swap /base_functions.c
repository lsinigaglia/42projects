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

#include "push_swap.h"

void	swap(the_stack **head_A)
{
	the_stack *temp;

	if (head_A == NULL || (*head_A)->next == NULL || (*head_A) == NULL)
		return ;
	temp = *head_A; // temp = 1->2
	(*head_A) = (*head_A)->next; // (*head_A) (1->2) = 2->3
	temp->next = (*head_A)->next; // temp = 1->3
	(*head_A)->next = temp; //(*head_A)->next = 2->1
}
void	do_sa(the_stack **head)
{
	swap(head);
	ft_printf("sa\n");
}

void	do_sb(the_stack **head)
{
	swap(head);
	ft_printf("sb\n");
}

void	do_ss(the_stack **headA, the_stack **headB)
{
	swap(headA);
	swap(headB);
	ft_printf("ss\n");
}

void	push(the_stack **head_A, the_stack **head_B)
{
	the_stack *tmp;

	if (head_A == NULL)
		return;
	tmp = (*head_A)->next;

	(*head_A)->next = (*head_B);
	*head_B = *head_A;
	*head_A = tmp;
}

void	do_pa(the_stack **head_A, the_stack **head_B)
{
	push(head_B, head_A);
	ft_putstr("pa\n");
}

void	do_pb(the_stack **head_A, the_stack **head_B)
{
	push(head_A, head_B);
	ft_putstr("pb\n");
}
/* the last element becomes the first one */
void	reverse_rotate(the_stack **head)
{
	the_stack *last;
	the_stack *second_last;

	if (!head || !*head || !(*head)->next) // Check if the list is empty or has only one element
		return;

	last = get_last_stack(*head);
	second_last = get_second_last_stack(*head);
	second_last->next = NULL;
	last->next = (*head);
	(*head) = last;
}

void	do_rra(the_stack **head)
{
	reverse_rotate(head);
	ft_printf("rra\n");
}

void	do_rrb(the_stack **head)
{
	reverse_rotate(head);
	ft_printf("rrb\n");
}

void	do_rrr(the_stack **headA, the_stack **headB)
{
	reverse_rotate(headA);
	reverse_rotate(headB);
	ft_printf("rrr\n");
}
/* the first element becomes the last one */
void rotate(the_stack **head)
{
	the_stack *last;
	the_stack *original_head;

	if (!head || !*head || !(*head)->next) // Check if the list is empty or has only one element
		return;

	original_head = (*head); // Store the original head node temp = 1->2
	last = get_last_stack(*head); // Find the last node in the list 
	last->next = original_head; // Point the next pointer of the last node to the current head last->next = 1->2
    ft_printf("Last: %d", (*head)->original_number);
	(*head) = (*head)->next; // Update the head pointer to the second node in the original list 
	original_head->next = NULL; // Set the next pointer of the original head to NULL
}

void	do_ra(the_stack **head)
{
	rotate(head);
	ft_printf("ra\n");
}

void	do_rb(the_stack **head)
{
	rotate(head);
	ft_printf("rb\n");
}

void	do_rr(the_stack **headA, the_stack **headB)
{
	rotate(headA);
	rotate(headB);
	ft_printf("rr\n");
}