/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:02:11 by lsinigag          #+#    #+#             */
/*   Updated: 2023/06/16 23:30:11 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

typedef struct stack
{
	int				original_number;
	int				cardinal_number;
	int				position;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct stack	*next;
}	t_stack;

/* list making */
t_stack	*ft_lstmake(int number);
t_stack	*ft_lstsecondlast(t_stack *lst);
t_stack	*get_last_stack(t_stack *head);
t_stack	*get_second_last_stack(t_stack *head);
void	ft_add_to_last(t_stack **head, t_stack *new);

/* initialization */
t_stack	*make_stack_a(int argc, char **argv);
void	assign_index(t_stack *stack_a, int stack_size);
int		get_stack_size(t_stack *head);
int		ft_check_atoi(const char *str);

/* sorts */
int		sorted_check(t_stack *head_a);
void	three_sort(t_stack **head_a);
void	do_push_swap(t_stack **head_a, t_stack **head_b, int stack_size);
void	big_push(t_stack **head_a, t_stack **head_b, int stack_size);
void	lets_push_swap(t_stack **head_a, t_stack **head_b, int stack_size);
void	final_rotate(t_stack **head_a);

/* positions*/
void	get_pos(t_stack **head_a);
int		get_target_pos(t_stack **head_a, int b_card);
int		get_target_min(t_stack **head_a);
void	lets_get_position(t_stack **head_a, t_stack **head_b);

/* cost */
void	get_cost(t_stack **head_a, t_stack **head_b);

/* input check */
int		are_you_sure_about_the_input(char **argv);
int		not_number_found(char *s);
int		duplicate_found(char **argv);
int		wrong_zero_yes(char **argv);
int		ft_strncmp_pl(char *ptr1, char *ptr2, size_t n);

/* basic functions */
void	swap(t_stack **head_a);
void	push(t_stack **head_a, t_stack **head_b);
void	rotate(t_stack **head);
void	reverse_rotate(t_stack **head);
void	rr(t_stack **head_a, t_stack **head_b);
void	rra(t_stack **head_a, t_stack **head_b);
void	ss(t_stack **head_a, t_stack **head_b);

/* utils */
int		ft_check_atoi(const char *str);
void	print_list_contents(t_stack *head);
void	free_stack(t_stack **stack, int *flag, char **argv);
int		abs(int number);
void	free_argv(char **argv, int flag);

/* do moves */
void	do_pb(t_stack **stack_a, t_stack **stack_b);
void	do_pa(t_stack **stack_a, t_stack **stack_b);
void	do_ra(t_stack **head);
void	do_rb(t_stack **head);
void	do_sa(t_stack **head);
void	do_sb(t_stack **head);
void	do_rra(t_stack **head);
void	do_rrb(t_stack **head);
void	do_ss(t_stack **heada, t_stack **headb);
void	do_rr(t_stack **heada, t_stack **headb);
void	do_rrr(t_stack **heada, t_stack **headb);

/* advanced moves */
void	do_cheapest_move(t_stack **head_a, t_stack **head_b);
void	the_move(t_stack **head_a, t_stack **head_b, int a, int b);
void	the_move_help(t_stack **head_b, int *b);

#endif
