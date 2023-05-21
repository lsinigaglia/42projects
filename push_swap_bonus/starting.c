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

t_stack	*make_stack_A(int argc, char **argv)
{
	int			i;
	t_stack	*tmp;
	t_stack	*anchor;

	tmp = ft_lstmake(ft_check_atoi(argv[1]));
	anchor = tmp;

	i = 2;
	while (i < argc)
	{
		tmp = ft_lstmake(ft_check_atoi(argv[i]));
		ft_add_to_last(&anchor, tmp);
		i++;
	}
	return (anchor);
}

void assign_index(t_stack *stack_a, int stack_size)
{
    t_stack *ptr;
    t_stack *highest;
    long int value;

    while (stack_size > 0)
    {
        ptr = stack_a;
        value = -2147483649;
        highest = NULL;
        while (ptr)
        {
            if (ptr->original_number > value && ptr->cardinal_number == 0)
            {
                value = ptr->original_number;
                highest = ptr;
            }
            ptr = ptr->next;
        }
        highest->cardinal_number = stack_size;
        stack_size--;
    }
}

int get_stack_size(t_stack *head)
{
    int i;

    i = 0;
    while (head)
    {
        head = head->next;
        i++;
    }
    return i;
}