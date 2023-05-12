/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:02:11 by lsinigag          #+#    #+#             */
/*   Updated: 2023/04/25 03:16:43 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"

typedef	struct stack
{
	int				original_number;
	int				cardinal_number;
	int				position;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct stack	*next;
} the_stack;

/* list making */
the_stack	*ft_lstmake(int number);
the_stack	*ft_lstsecondlast(the_stack *lst);
the_stack	*get_last_stack(the_stack *head);
the_stack   *get_second_last_stack(the_stack* head);
void		ft_add_to_last(the_stack **head, the_stack *new);

/* initialization */
the_stack	*make_stack_A(int argc, char **argv);
void assign_index(the_stack *stack_a, int stack_size);
int get_stack_size(the_stack *head);

/* sorts */
int	sorted_check(the_stack *head_A);
void	three_sort(the_stack **head_A);
void	do_push_swap(the_stack **head_A, the_stack **head_B, int stack_size);
void    big_push(the_stack **head_A, the_stack **head_B, int stack_size);
void	lets_push_swap (the_stack **head_A, the_stack **head_B, int stack_size);

/* basic functions */
void	swap(the_stack **head_A);
void	push(the_stack **head_A, the_stack **head_B);
void	rotate(the_stack **head);
void	reverse_rotate(the_stack **head);
void	rr(the_stack **head_A, the_stack **head_B);
void	rra(the_stack **head_A, the_stack **head_B);
void	ss(the_stack **head_A, the_stack **head_B);

/* utils */
int		ft_check_atoi(const char *str);
void	print_list_contents(the_stack *head);
void	free_stack(the_stack **stack);

/* do moves */
void	do_pb(the_stack **stack_a, the_stack **stack_b);
void	do_pa(the_stack **stack_a, the_stack **stack_b);
void	do_ra(the_stack **head);
void	do_rb(the_stack **head);
void	do_sa(the_stack **head);
void	do_sb(the_stack **head);
void	do_rra(the_stack **head);
void	do_ss(the_stack **headA, the_stack **headB);
void	do_rr(the_stack **headA, the_stack **headB);
void	do_rrr(the_stack **headA, the_stack **headB);

#endif
