/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PROVEmain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:44:15 by lsinigag          #+#    #+#             */
/*   Updated: 2023/04/03 19:11:51 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_nothing(void *content)
{
	(void)content;
}
void print_list_contents(t_list *head)
{
	t_list *current = head;
	while (current != NULL)
	{
		printf("Node content: %d\n", *(int *)(current->content));
		current = current->next;
	}
}
void	make_stack_A(int argc, char **argv, t_list *head_A)
{
	int		i;
	t_list	*pointer_A;
	int		*number;

	i = 0;
	while (++i < argc)
	{
		number = malloc(sizeof(int));
		*number = ftcheck_atoi(argv[i]);
		if (head_A->content != NULL)
		{
			pointer_A = ft_lstnew(number);
			// printf("%c", pointer_A->content);
			ft_lstadd_back(&head_A, pointer_A);
			printf("number:%d\n", *(int *)(pointer_A->content));
		}
		if (head_A->content == NULL)
		{
			head_A->content = number;
			printf("number:%d\n", *number);
		}
	}
}

int main (int argc, char **argv)
{
	t_list *head_A;
	t_list *head_B;
	int i = 0;

	head_A = ft_lstnew(NULL);
	head_B = ft_lstnew(NULL);
	make_stack_A(argc, argv, head_A);
	while (i++ < 5)
		push(&head_A, &head_B); // push b
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
	ft_lstclear(&head_B, free);
	ft_lstclear(&head_A, free);
}
