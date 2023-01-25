#include <stdio.h>
#include <stdlib.h>

typedef struct    s_list
{
    void           *data;
    struct s_list *next;
}                 t_list;

int ft_lstsize(t_list *lst)
{
    if (lst == NULL)
        return (0);
    else
        return (1 + ft_lstsize(lst->next));
}

int main(void)
{
    t_list *list = NULL; // Initialize an empty list
    t_list *new = (t_list*)malloc(sizeof(t_list)); // Allocate memory for the first element
    new->data = NULL; // Set the data for the first element
    new->next = NULL; // Set the next pointer to NULL
    list = new;
    new = (t_list*)malloc(sizeof(t_list)); // Allocate memory for the second element
    new->data = NULL; // Set the data for the second element
    new->next = NULL;
    list->next = new;
    new = (t_list*)malloc(sizeof(t_list)); // Allocate memory for the third element
    new->data = NULL; // Set the data for the third element
    new->next = NULL;
    list->next->next = new;
    printf("The size of the list is %d\n", ft_lstsize(list));
    return (0);
}
