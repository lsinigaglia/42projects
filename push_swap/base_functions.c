/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:02:07 by lsinigag          #+#    #+#             */
/*   Updated: 2023/03/27 14:30:14 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_list *head_A)
{
	t_list	*temp_1;
	t_list	*temp_2;

	temp_1 = head_A->next;
	head_A->next = head_A->next->next;

	temp_2 = head_A->next->next;
	head_A->next->next = temp_1;

	temp_1->next = temp_2;

}

void	push(t_list *head_A, t_list *head_B)
{
	t_list *temp_1;
	t_list *temp_2;

	temp_1 = head_A->next;
	head_A->next = head_A->next->next;

	temp_2 = head_B->next;
	head_B->next = temp_1;

	temp_1->next = temp_2;
}

void	reverse_rotate(t_list *head)
{
	t_list	*temp_1;
	//t_list	*temp_2;
	t_list	*new_first;

	temp_1 = head->next;
	//temp_2 = head->next->next;
	new_first = ft_lstsecondlast(head);
	head->next = new_first->next;
	head->next->next = temp_1;
	new_first->next = NULL;

}

void	rotate(t_list *head)
{
	t_list	*temp_1;
	t_list	*temp_2;
	t_list	*new_first;

	temp_1 = head->next;
	temp_2 = head->next->next;
	new_first = ft_lstsecondlast(head);
	new_first->next = temp_1;
	temp_1->next = temp_2;
	temp_1->next = NULL;

}
