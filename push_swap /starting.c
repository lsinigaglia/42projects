#include "push_swap.h" 

the_stack	*make_stack_A(int argc, char **argv)
{
	int			i;
	the_stack	*tmp;
	the_stack	*anchor;

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

void assign_index(the_stack *stack_a, int stack_size)
{
    the_stack *ptr;
    the_stack *highest;
    int value;

    while (--stack_size > 0)
    {
        ptr = stack_a;
        value = -2147483648;
        highest = NULL;
        while (ptr)
        {
            if (ptr->original_number == -2147483648 && ptr->cardinal_number == 0)
                ptr->cardinal_number = 1;
            if (ptr->original_number > value && ptr->cardinal_number == 0)
            {
                value = ptr->original_number;
                highest = ptr;
                //ptr = stack_a;
            }
            //else
            ptr = ptr->next;
        }
        if (highest != NULL)
            highest->cardinal_number = stack_size;
    }
}