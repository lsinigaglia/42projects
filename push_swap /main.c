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

/* void	replace_number(t_list *head)
{

} */
/* void print_list_contents(the_stack *head)
{
	the_stack *current = head;
	while (current != NULL)
	{
		printf("Node content: %d\n", *(int *)(current->content));
		current = current->next;
	} */
//}


int main (int argc, char **argv)
{
	the_stack *head_A;
	//the_stack *head_B;
	//int i = 0;

	head_A = make_stack_A(argc, argv);
	assign_index(head_A, 5);
	print_list_contents(head_A);
	free_stack(&head_A);
}
/* 	head_B = ft_lstnew(NULL);
	while (i++ < 4)
		push(&head_A, &head_B); // push b
	i = 0;
	while (i++ < 4)
		push(&head_B, &head_A); // push b
	// while
	// swap(&head_A);


	// // swap(head_A);
	// ss(head_A, head_B); // double swap
	// reverse_rotate(head_A);
	reverse_rotate(&head_A);
	while (head_A != NULL)
	{
		ft_printf("Stack A:%d\n", *(int *)(head_A->content));
		head_A = head_A->next;
	}
	while (head_B != NULL)
	{
		ft_printf("Stack B:%d\n", *(int *)(head_B->content));
		head_B = head_B->next;
	}
	// ft_lstclear(&head_B, free);
	free_stack(&head_A); */
