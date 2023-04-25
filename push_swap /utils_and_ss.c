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

t_list	*ft_lstsecondlast(t_list *lst)
{
	if (!lst || !(lst->next))
		return (NULL);
	while (lst->next->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

/*swap a and swap b at the same time*/
void ss(t_list **head_A, t_list **head_B)
{
	// t_list *temp;
	swap(head_A);
	swap(head_B);
}

/*ra and rb at the same time.*/
void	rr(t_list **head_A, t_list **head_B)
{
	rotate(head_A);
	rotate(head_B);
}
/* rra and rrb at the same time */
void	rrr(t_list **head_A, t_list **head_B)
{
	reverse_rotate(head_A);
	reverse_rotate(head_B);
}

int	ftcheck_atoi(const char *str)
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
void	free_stack(t_list **stack)
{
	t_list	*tmp;

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
