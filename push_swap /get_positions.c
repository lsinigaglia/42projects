#include "push_swap.h"

void get_pos(the_stack **head_A)
{
    the_stack *temp;
    int i;

    i = 0;
    temp = *head_A;
    while (temp)
    {
        temp->position = i;
        i++;
        temp = temp->next;
    }
}

int get_target_pos(the_stack **head_A, int b_card, int tar_b, int target_pos)
{
    the_stack *temp;

    temp = *head_A;
    while(temp)
    {
        if (temp->cardinal_number > b_card && temp->cardinal_number < tar_b)
        {
            target_pos = temp->position;
            tar_b = temp->cardinal_number; 
        }
        temp = temp->next;
    }
    if (tar_b != 2147483647)
        return (target_pos);
    temp = *head_A;
    
}