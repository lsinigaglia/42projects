
#include "push_swap.h"



int main ()
{
    int nb = 10;
    int nb1 = 20;
    int nb2 = 30;
    int nb3 = 40;

    the_stack* example;
    the_stack* example1;
    the_stack* example2;
    the_stack* example3;

    example = ft_lstmake(nb);
    example1 = ft_lstmake(nb1);
    example2 = ft_lstmake(nb2);
    example3 = ft_lstmake(nb3);

    ft_add_to_last(&example, example1);
    ft_add_to_last(&example, example2);
    ft_add_to_last(&example, example3);

    rotate(&example);
   /*  printf("Node content: %d\n", (example->original_number));
    printf("Node content: %d\n", (example1->original_number));
    printf("Node content: %d\n", (example2->original_number));
    printf("Node content: %d\n", (example3->original_number)); */
    print_list_contents(example);
    //ft_printf("%d", example->next->original_number);
}