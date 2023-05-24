/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:37:31 by lsinigag          #+#    #+#             */
/*   Updated: 2023/05/24 16:31:17 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"

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

/* input check */
int		are_you_sure_about_the_input(char **argv);
int		not_number_found(char *s);
int		duplicate_found(char **argv);
int		wrong_zero_yes(char **argv);
int		ft_strncmp_pl(char *ptr1, char *ptr2, size_t n);

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

/* basic functions */
void	swap(t_stack **head_a);
void	push(t_stack **head_a, t_stack **head_b);
void	rotate(t_stack **head);
void	reverse_rotate(t_stack **head);
void	do_rr(t_stack **head_a, t_stack **head_b);
void	do_rrr(t_stack **head_a, t_stack **head_b);
void	rra(t_stack **head_a, t_stack **head_b);
void	ss(t_stack **head_a, t_stack **head_b);

/* make_move.c */

void	make_move(t_stack **head_a, t_stack **head_b, char *line);
int		the_check(int argc, char **argv);
int		sorted_check(t_stack *head_a);
void	free_stack(t_stack **stack);

void	ft_add_to_last(t_stack **head, t_stack *new);
t_stack	*ft_lstmake(int number);
t_stack	*get_second_last_stack(t_stack *head);
t_stack	*get_last_stack(t_stack *head);

#endif