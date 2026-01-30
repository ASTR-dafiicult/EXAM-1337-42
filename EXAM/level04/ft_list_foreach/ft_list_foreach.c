//# include <stdio.h>
# include "ft_list.h"
/*
void f(void *data)
{
    printf("%d\n", *(int *)data);
}
*/
void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    t_list *current;

    current = begin_list;

    while(current)
    {
        (*f)(current->data);
        current = current->next;
    }
}
/*
int main()
{
    t_list node1;
    t_list node2;
    t_list node3;
    
    int a = 10, b = 20, c = 30;

    node1.data = &a;
    node1.next = &node2;
    node2.data = &b;
    node2.next = &node3;
    node3.data = &c;
    node3.next = NULL;
    
    ft_list_foreach(&node1, f);
}
*/
