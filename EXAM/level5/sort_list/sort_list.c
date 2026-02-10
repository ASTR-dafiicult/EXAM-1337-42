# include "sort_list.h"
# include <stdio.h>
# include <stdlib.h>


int cmp(int a, int b)
{
    return (a - b);
}
t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    t_list *curr;
    int access = 1;
    int tmp = 0;

    while(access)
    {
        access = 0;
        curr = lst;
        while(curr->next)
        {
            if((*cmp)(curr->data, curr->next->data) > 0)
            {
                tmp = curr->data;
                curr->data = curr->next->data;
                curr->next->data = tmp;
                access = 1;
            }
            curr = curr->next;
        }
    }
    curr = lst;
    return curr;
}
void print_list(t_list *node)
{
    while(node)
    {
        printf("%d\n", node->data);
        node = node->next;
    }
}
int main()
{
    
    t_list *node1 = malloc(sizeof(t_list));
    t_list *node2 = malloc(sizeof(t_list));
    t_list *node3 = malloc(sizeof(t_list));
    

    int a = 100, b = 30, c = 5;
    
    node1->data = a;
    node1->next = node2;   
    node2->data = b;
    node2->next = node3;   
    node3->data = c;
    node3->next = NULL;

    t_list *head = sort_list(node1, cmp);
    print_list(head);

    free(node1);
    free(node2);
    free(node3);

}