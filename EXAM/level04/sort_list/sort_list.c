# include "sort.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    t_list *ptr;
    int tmp;
    int access = 1;
    
    while(access)
    {
        access = 0;
        ptr = lst;
        while(ptr->next)
        {
            if((*cmp)(ptr->data, ptr->next->data) > 0)
            {
                tmp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = tmp;
                access = 1;
            }
            ptr = ptr->next;
        }
    }
    ptr = lst;
    return ptr;
}