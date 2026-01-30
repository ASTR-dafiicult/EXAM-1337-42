# include <stdlib.h>
# include "ft_list.h"


void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list *current; //current node
    t_list *prev; // previous node
    t_list *tmp; // delete node
    
    current = *begin_list;
    prev = NULL;

    while(current)
    {
        if(!cmp(current->data, data_ref))
        {
            tmp = current;
            if(prev == NULL)
            {
                *begin_list = current->next;// pointe to next val
            }
            else
                prev->next = current->next;

            current = current->next;
            free(tmp); // remove current == data_ref
        }
        else{
            prev = current;
            current = current->next;
        }
    }
}
# include <stdio.h>

int cmp_val(void *b1, void *b2)
{
    if(*(int *)b1 == *(int *)b2) // 4  == 5
    {
        return 0;
    }
    return 1;
}
void push(t_list **node, int data_add)
{
    t_list *new;
    t_list *tmp;
    int *data;

    data = malloc(sizeof(int));
    *data = data_add;

    new = malloc(sizeof(t_list));
    new->data = data;
    new->next = NULL;

    if(!*node)
    {
        *node = new;
        return;
    }
    tmp = *node;
    while(tmp->next)
        tmp = tmp->next;

    tmp->next = new;
}
void print_list(t_list *node)
{
    while(node)
    {
        printf("%d ", *(int*) node->data);
        node = node->next;
    }
}
int main()
{
    t_list *head = NULL;
    int data_rem = 4;

    push(&head, 4);
    push(&head, 2);
    push(&head, 4);
    push(&head, 7);
    push(&head, 9);

    print_list(head);
    printf("\n");
    ft_list_remove_if(&head, &data_rem, cmp_val);

    print_list(head);
    printf("\n");
}