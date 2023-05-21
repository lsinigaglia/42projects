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

int	main(int argc, char **argv)
{
	int stack_size;
	t_stack *head_A;
	t_stack *head_B;
	char *line;

	if (!(the_check(argc, argv)))
		return (0);
	head_A = make_stack_A(argc, argv);
	head_B = NULL;
	stack_size = get_stack_size(head_A);
	assign_index(head_A, stack_size);
	line = get_next_line(0);
	while (line)
	{
		make_move(&head_A, &head_B, line);
		free(line);
		line = get_next_line(0);
	}
	if (!sorted_check(head_A))
		ft_printf("KO");
	else if (sorted_check(head_A))
		ft_printf("OK");
	// while (head_A != NULL)
	// {
	// 	printf("Node content: %d\n", (head_A->cardinal_number));
	//  	/* printf("Node cost_a: %d\n", (head->cost_a));
	// 	printf("Node cost_b: %d\n", (head->cost_b));  */
	// 	head_A = head_A->next;
	// } 
	free(head_A);
	free(head_B);
}