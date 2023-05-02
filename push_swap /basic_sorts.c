#include "push_swap.h"

int sorted_check(the_stack *head_A)
{
    while (head_A->next)
    {
        if (head_A->cardinal_number > head_A->next->cardinal_number)
            return (0);
        head_A = head_A->next;
    }
    return (1);
}

void    three_sort(the_stack **head_A)
{

    if (sorted_check(*head_A))
       return;
    if ((*head_A)->cardinal_number == 3)
        do_ra(head_A);
    if ((*head_A)->next->cardinal_number == 3)
        do_rra(head_A);
    if(sorted_check(*head_A))
        return;
    do_sa(head_A);
}