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

int main (int argc, char **argv)
{
	int stack_size;
	the_stack *head_A;
	the_stack *head_B;

	if (argc < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	if (!(are_you_sure_about_the_input(argv)))
	{
		ft_printf("Error\n");
		return (0);
	}
	head_A = make_stack_A(argc, argv);
	head_B = NULL;
	stack_size = get_stack_size(head_A);
	assign_index(head_A, stack_size);
	do_push_swap(&head_A, &head_B, stack_size);
	free_stack(&head_A);
	free_stack(&head_B);
}