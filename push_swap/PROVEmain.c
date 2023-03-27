/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PROVEmain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:44:15 by lsinigag          #+#    #+#             */
/*   Updated: 2023/03/27 17:59:29 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_nothing(void *content)
{
	(void)content;
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
		number[i] = ftcheck_atoi(argv[i]);
		printf("number:%d\n", number[i]);
		pointer_A = ft_lstnew(&number[i]);
		// printf("%c", pointer_A->content);
		ft_lstadd_back(&head_A, pointer_A);
	}
}

int main (int argc, char **argv)
{
	t_list *head_A;
	t_list *head_B;

	head_A = ft_lstnew(NULL);
	head_B = ft_lstnew(NULL);
	make_stack_A(argc, argv, head_A);
	// swap(head_A);
	push(head_A, head_B); // push b
	// reverse_rotate(head_A);
	while (head_A->next != NULL)
	{
		head_A = head_A->next;
		ft_printf("after ops:%d\n", (head_A->content));
	}
	while (head_B->next != NULL)
	{
		head_B = head_B->next;
		ft_printf("\n%s", (head_B->content));
	}
	ft_lstclear(&head_B, do_nothing);
	ft_lstclear(&head_A, do_nothing);
}
