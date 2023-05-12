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

#include "push_swap.h"

void    big_push(the_stack **head_A, the_stack **head_B, int stack_size)
{
    int i;

    i = 0;
    while (stack_size > 6 && i < stack_size / 2)
    {
        if ((*head_A)->cardinal_number > stack_size / 2)
        {
            do_pb(head_A, head_B);
            i++;
        }
        else
            do_ra(head_A);
    }
    while (stack_size - i > 3)
    {
        do_pb(head_A, head_B);
        i++;
    }
}

void lets_push_swap (the_stack **head_A, the_stack **head_B, int stack_size)
{
    big_push(head_A, head_B, stack_size);
    three_sort(head_A);
}