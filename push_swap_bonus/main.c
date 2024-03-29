/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:02:07 by lsinigag          #+#    #+#             */
/*   Updated: 2023/06/17 00:54:03 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char **argv)
{
	int		stack_size;
	t_stack	*head_a;
	t_stack	*head_b;
	char	*line;
	int		flag;

	flag = 0;
	if (!(the_check(argc, &argv, &flag)))
		return (0);
	head_a = make_stack_a(argv);
	head_b = NULL;
	stack_size = get_stack_size(head_a);
	assign_index(head_a, stack_size);
	line = get_next_line(0);
	while (line)
	{
		//va in segfault dentro makemove
		make_move(&head_a, &head_b, line);
		free(line);
		line = get_next_line(0);
	}
	if (!sorted_check(head_a))
		ft_printf("KO");
	else if (sorted_check(head_a))
		ft_printf("OK");
	free_stack(&head_a, &flag, argv);
}
