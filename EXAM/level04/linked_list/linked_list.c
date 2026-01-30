# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "list.h"

// insert nodes
void insert_node(t_list **begin, int val)
{
    t_list *node;
    t_list *tmp;
    node = malloc(sizeof(t_list));
    
    if(!node)
    {
        return;
    }
    node->data = val;
    node->next = NULL;
    if(!*begin)
    {
        *begin = node;
    }
    else{
        tmp = *begin;
        while(tmp->next)//check next == NULL
        {
            tmp = tmp->next; // go next
        }
        tmp->next = node;
    }
}
// sort array in ascending order
int cmp(int a, int b)
{
    return (a - b);
}
t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    t_list *node;
    int tmp;
    int acc = 1;

    while(acc)
    {
        acc = 0;
        node = lst;//when done start over
        while(node->next)
        {
            if((*cmp)(node->data, node->next->data) > 0)
            {
                tmp = node->data;
                node->data = node->next->data;
                node->next->data = tmp;
                acc = 1;
            }
            node = node->next;
        }
    }
    node = lst;
    return node;
}
// insert void data
void insert_void_node(rem_list **begin, void *data)
{
    rem_list *new;
    rem_list *tmp;

    new = malloc(sizeof(rem_list));
    if(!new)
        return;

    new->data = data;
    new->next = NULL;
    if(!*begin)
    {
        *begin = new;
    }
    else{
        tmp = *begin;
        while(tmp->next)
        {
            tmp = tmp->next;
        }
        tmp->next = new;
    }
}

// remove elements from list
int cmp2(void *a, void *b)
{
    if(*(int*)a == *(int*)b)
    {
        return 1;
    }
    return 0;
}
void ft_list_remove_if(rem_list **begin_list, void *data_ref, int (*cmp2)())
{
    rem_list *curr;
    rem_list *prev;
    rem_list *free_it;

    curr = *begin_list;
    prev = NULL;
    while(curr)
    {
        if(cmp2(curr->data, data_ref))
        {
            free_it = curr;
            
            if(prev == NULL)
            {
                *begin_list = curr->next;
            }
            else{
                prev->next = curr->next;
            }
            curr = curr->next;
            free(free_it);
        }
        else{
            prev = curr;
            curr = curr->next;
        }
    }
}
//print t_list int data
void print_list(t_list *node)
{
    while(node)
    {
        printf("%d \n", node->data);
        node = node->next;
    }
}
//print rem_list void data
void print_rem_list(rem_list *node)
{
    while(node)
    {
        printf("%d\n", *(int *)node->data);
        node = node->next;
    }
}
int counter(t_list *node)
{
    int i = 0;
    while(node)
    {
        node = node->next;
        i++;
    }
    return i;
}
int counter2(rem_list *node)
{
    int i = 0;
    while(node)
    {
        node = node->next;
        i++;
    }
    return i;
}
int main()
{
    t_list *head = NULL;
    int a = 12, b = 20, c = 42, d = 11, e = 20;
    insert_node(&head, a);
    insert_node(&head, b);
    insert_node(&head, c);
    insert_node(&head, d);
    insert_node(&head, e);
    
    printf("-------------insert list---------\n");
    print_list(head);
    printf("N-nodes : %d\n", counter(head));
    t_list *node1 = malloc(sizeof(t_list));
    t_list *node2 = malloc(sizeof(t_list));
    t_list *node3 = malloc(sizeof(t_list));
    t_list *node4 = malloc(sizeof(t_list));
    t_list *node5 = malloc(sizeof(t_list));
    head = node1;

    node1->data = a;
    node2->data = b;
    node3->data = c;
    node4->data = d;
    node5->data = e;

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;
    
    sort_list(head, cmp);
    printf("-------------sorted list-------------\n");
    print_list(head);
    printf("N-nodes : %d\n", counter(head));
    
    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(node5);

    rem_list *head2 = NULL;
    int data_ref = 20;
    insert_void_node(&head2, &a);
    insert_void_node(&head2, &b);
    insert_void_node(&head2, &c);
    insert_void_node(&head2, &d);
    insert_void_node(&head2, &e);

    ft_list_remove_if(&head2, &data_ref, cmp2);
    printf("-------------remove %d from list--------\n", data_ref);
    print_rem_list(head2);
    printf("N-nodes : %d\n", counter2(head2));
}