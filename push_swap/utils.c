/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:29:48 by lsinigag          #+#    #+#             */
/*   Updated: 2023/06/16 23:30:00 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list_contents(t_stack *head)
{
	while (head != NULL)
	{
		printf("Node content: %d\n", (head->cardinal_number));
		head = head->next;
	}
}

int	ft_check_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = str[i] - 48 + (res * 10);
		i++;
	}
	if (str[i] < '0' && str[i] > '9')
	{
		ft_printf("error");
		return (0);
	}
	return (res * sign);
}
/* free_stack:
*	Frees each element in a given stack and sets the stack pointer to NULL.
*/

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

void	free_argv(char **argv, int flag)
{
	int	i;

	i = -1;
	if (flag == 1)
	{
		while (argv[++i])
			free(argv[i]);
		free(argv);
	}
}
