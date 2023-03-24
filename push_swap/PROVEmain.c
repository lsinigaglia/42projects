/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PROVEmain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:44:15 by lsinigag          #+#    #+#             */
/*   Updated: 2023/03/24 21:12:24 by lsinigag         ###   ########.fr       */
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

	i = 0;
	while (++i < argc)
	{
		pointer_A = ft_lstnew(argv[i]);
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
	// push(head_A, head_B);
	rotate(head_A);
	while (head_A->next != NULL)
	{
		head_A = head_A->next;
		ft_printf("%s", (head_A->content));
	}
	while (head_B->next != NULL)
	{
		head_B = head_B->next;
		ft_printf("\n%s", (head_B->content));
	}
	ft_lstclear(&head_B, do_nothing);
}
