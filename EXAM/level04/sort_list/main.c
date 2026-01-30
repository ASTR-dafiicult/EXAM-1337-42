# include "sort.h"
# include <stdlib.h>
# include <stdio.h>

int cmp(int a, int b)
{
    return (a - b);
}
t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    int tmp = 0;
    int access = 1;
    t_list *ptr;

    while(access)
    {
        access = 0; // to exit loop
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
            ptr = ptr->next; //go next
        }
    }
    ptr = lst;
    return ptr;
}
void print_list(t_list *node)
{
    while(node)
    {
        printf("%d  \n", node->data);
        node = node->next;
    }
}
int main()
{
    t_list *node1 = malloc(sizeof(t_list));
    t_list *node2 = malloc(sizeof(t_list));
    t_list *node3 = malloc(sizeof(t_list));
    t_list *node4 = malloc(sizeof(t_list));
    t_list *node5 = malloc(sizeof(t_list));


    int a = 10, b = 5, c = 1, d = 9, e = 12;

    t_list *head = node1;

    node1->data = a;
    node1->next = node2;
    node2->data = b;
    node2->next = node3;
    node3->data = c;
    node3->next = node4;
    node4->data = d;
    node4->next = node5;
    node5->data = e;
    node5->next = NULL;

    sort_list(head, cmp);
    print_list(head);

    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(node5);
}