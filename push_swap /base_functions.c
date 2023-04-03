/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:02:07 by lsinigag          #+#    #+#             */
/*   Updated: 2023/04/03 18:36:51 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_list **head_A)
{
	t_list *temp;

	temp = *head_A;
	(*head_A) = (*head_A)->next;
	temp->next = (*head_A)->next;
	(*head_A)->next = temp;

}

void	push(t_list **head_A, t_list **head_B)
{
	t_list *temp_1;
	// t_list *temp_2;

	if ((*head_B)->content == NULL || !(*head_B))
	{
		(*head_B)->content = (*head_A)->content;
		(*head_B)->next = NULL;
		(*head_A) = (*head_A)->next;
		return;
	}
	temp_1 = (*head_A)->next;

	(*head_A)->next = (*head_B);
	*head_B = *head_A;
	*head_A = temp_1;
}

void	reverse_rotate(t_list **head)
{
	t_list *last;
	t_list *second_last;

	if (!head || !*head || !(*head)->next) // Check if the list is empty or has only one element
		return;
	last = ft_lstlast(*head);
	second_last = ft_lstsecondlast(*head);
	second_last->next = NULL;
	last->next = (*head);
	(*head) = last;
}

void rotate(t_list **head)
{
	t_list *last;
	t_list *original_head;

	if (!head || !*head || !(*head)->next) // Check if the list is empty or has only one element
		return;

	original_head = (*head); // Store the original head node
	last = ft_lstlast(*head); // Find the last node in the list
	last->next = (*head); // Point the next pointer of the last node to the current head
	(*head) = (*head)->next; // Update the head pointer to the second node in the original list
	original_head->next = NULL; // Set the next pointer of the original head to NULL
}

