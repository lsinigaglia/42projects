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
	the_stack *head_A;
	int stack_size;
	the_stack *head_B;

	head_A = make_stack_A(argc, argv);
	head_B = NULL;
	stack_size = get_stack_size(head_A);
	assign_index(head_A, stack_size);
	/* do_pb(&head_A, &head_B);
 	do_pb(&head_A, &head_B);
	do_pb(&head_A, &head_B); */
	/* do_pb(&head_A, &head_B);
	do_pb(&head_A, &head_B);
	do_pb(&head_A, &head_B); */ 
	/* the_move(&head_A, &head_B, 1, -1); */
	do_push_swap(&head_A, &head_B, stack_size); 
	/* lets_get_position(&head_A, &head_B); 
	get_cost(&head_A, &head_B); */ 


	/* lets_get_position(&head_A, &head_B);
	get_cost(&head_A, &head_B); */
	
	//print_list_contents(head_A);
	//print_list_contents(head_A);
	//ft_printf("list B \n");
	print_list_contents(head_A);

	free_stack(&head_A);
	free_stack(&head_B);

	//free_stack(&head_B);

}
