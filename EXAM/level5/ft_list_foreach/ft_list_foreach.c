# include <stdio.h>
# include "list.h"


void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    t_list *node;

    node = begin_list;
    while(node)
    {
        f(node->data);
        node = node->next;
    }
}
void f(void *a)
{
    printf("%d\n", *(int *)a);
}
# include <stdlib.h>
int main()
{
    int a = 1, b = 20, c = 30;
    t_list *head;
    
    t_list *node1 = malloc(sizeof(t_list));
    t_list *node2 = malloc(sizeof(t_list));
    t_list *node3 = malloc(sizeof(t_list));

    head = node1;

    node1->data = &a;
    node2->data = &b;
    node3->data = &c;

    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    ft_list_foreach(head, f);
}