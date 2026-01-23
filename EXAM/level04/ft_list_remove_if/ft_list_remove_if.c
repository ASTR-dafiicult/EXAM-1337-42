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
                *begin_list = current->next;
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