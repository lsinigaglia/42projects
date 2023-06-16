/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 00:09:48 by lsinigag          #+#    #+#             */
/*   Updated: 2023/06/16 23:22:44 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	make_move(t_stack **head_a, t_stack **head_b, char *line)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		swap(head_a);
	if (ft_strncmp(line, "sb\n", 3) == 0)
		swap(head_b);
	if (ft_strncmp(line, "ss\n", 3) == 0)
		ss(head_a, head_b);
	if (ft_strncmp(line, "pa\n", 3) == 0)
		push(head_b, head_a);
	if (ft_strncmp(line, "pb\n", 3) == 0)
		push(head_a, head_b);
	if (ft_strncmp(line, "ra\n", 3) == 0)
		rotate(head_a);
	if (ft_strncmp(line, "rb\n", 3) == 0)
		rotate(head_b);
	if (ft_strncmp(line, "rr\n", 3) == 0)
		do_rr(head_a, head_b);
	if (ft_strncmp(line, "rra\n", 4) == 0)
		reverse_rotate(head_a);
	if (ft_strncmp(line, "rrb\n", 4) == 0)
		reverse_rotate(head_b);
	if (ft_strncmp(line, "rrr\n", 4) == 0)
		do_rrr(head_a, head_b);
}

int	the_check(int argc, char ***argv, int *flag)
{
	if (argc < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	if (argc == 2)
	{
		*argv = ft_split((*argv)[1], ' ');
	}
	if (!(are_you_sure_about_the_input(*argv)))
	{
		ft_printf("Error\n");
		free_stack(NULL, flag, *argv);
		return (0);
	}
	return (1);
}

int	sorted_check(t_stack *head_a)
{
	while (head_a->next)
	{
		if (head_a->cardinal_number > head_a->next->cardinal_number)
			return (0);
		head_a = head_a->next;
	}
	return (1);
}

void	free_stack(t_stack **stack, int *flag, char **argv)
{
	t_stack	*tmp;
	int		i;

	i = -1;
	if (*flag == 1)
	{
		while (argv[++i])
			free(argv[i]);
		free(argv);
		*flag = 0;
	}
	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}
