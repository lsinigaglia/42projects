/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:44:15 by lsinigag          #+#    #+#             */
/*   Updated: 2023/06/16 23:55:08 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			stack_size;
	t_stack		*head_a;
	t_stack		*head_b;
	int			flag;

	flag = 0;
	if (argc < 2)
		return (0);
	else if (argc == 2)
	{
		flag = 1;
		argv = ft_split(argv[1], ' ');
	}
	if (!(are_you_sure_about_the_input(argv)))
	{
		ft_printf("Error\n");
		free_argv(argv, flag);
		return (0);
	}
	head_a = make_stack_a(argc, argv);
	head_b = NULL;
	stack_size = get_stack_size(head_a);
	assign_index(head_a, stack_size);
	do_push_swap(&head_a, &head_b, stack_size);
	free_stack(&head_a, &flag, argv);
}
