#include "push_swap.h"

the_stack   *get_last_stack(the_stack* head)
{
    while (head->next)
        head = head->next;
    return (head);
}

the_stack   *get_second_last_stack(the_stack* head)
{
    while (head->next->next)
        head = head->next;
    return (head);
}

the_stack   *ft_lstmake(int number)
{
    the_stack *new;

    new = (the_stack *)malloc(sizeof(the_stack));
    if (!new)
        return(NULL);
    new->original_number = number;
    new->cardinal_number = 0;
    new->position = -1;
    new->target_pos = -1;
    new->cost_a = -1;
    new->cost_b = -1;
    new->next = NULL;
    return (new);
}

void    ft_add_to_last(the_stack **head, the_stack *new)
{
    the_stack *last;

    if (!new)
        return;
    if (!*head)
    {
        *head = new;
        return;
    }
    last = get_last_stack(*head);
    last->next = new;
    return;
}