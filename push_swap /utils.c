/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_and_ss.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:29:48 by lsinigag          #+#    #+#             */
/*   Updated: 2023/04/24 23:47:00 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

 void print_list_contents(the_stack *head)
{
	while (head != NULL)
	{
		printf("Node content: %d\n", (head->cardinal_number));
	 	/* printf("Node cost_a: %d\n", (head->cost_a));
		printf("Node cost_b: %d\n", (head->cost_b));  */
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
void	free_stack(the_stack **stack)
{
	the_stack	*tmp;

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
