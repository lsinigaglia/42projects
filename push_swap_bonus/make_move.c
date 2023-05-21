/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 00:09:48 by lsinigag          #+#    #+#             */
/*   Updated: 2023/02/10 05:50:21 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void make_move(t_stack **head_A, t_stack **head_B, char *line)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		swap(head_A);
	if (ft_strncmp(line, "sb\n", 3) == 0)
		swap(head_B);
	if (ft_strncmp(line, "ss\n", 3) == 0)
		ss(head_A, head_B);
	if (ft_strncmp(line, "pa\n", 3) == 0)
		push(head_A, head_B);
	if (ft_strncmp(line, "pb\n", 3) == 0)
		push(head_B, head_A);
	if (ft_strncmp(line, "ra\n", 3) == 0)
		rotate(head_A);
	if (ft_strncmp(line, "rb\n", 3) == 0)
		rotate(head_B);
	if (ft_strncmp(line, "rr\n", 3) == 0)
		do_rr(head_A, head_B);
	if (ft_strncmp(line, "rra\n", 4) == 0)
		reverse_rotate(head_A);
	if (ft_strncmp(line, "rrb\n", 4) == 0)
		reverse_rotate(head_B);
	if (ft_strncmp(line, "rrr\n", 4) == 0)
		do_rrr(head_A, head_B);
}

int	the_check(int argc, char **argv)
{
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
	return(1);
}

int sorted_check(t_stack *head_A)
{
    while (head_A->next)
    {
        if (head_A->cardinal_number > head_A->next->cardinal_number)
            return (0);
        head_A = head_A->next;
    }
    return (1);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

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