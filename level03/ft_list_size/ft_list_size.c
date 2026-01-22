# include "ft_list_size.h"

int	ft_list_size(t_list *begin_list)
{
    int counter = 0;
    //methode is traversal process from head node to the last node counting nodes
    while(begin_list != NULL)
    {
    //node1/next ---> node2/next ----> node3/next ----> NULL
        begin_list = begin_list->next;
        counter++;
    }
    return counter;
}

/*
    <-----------TEST---------------->
# include <stdio.h>
# include <stdlib.h>
int main()
{
    <------------------------------------->
    t_list *node1 = malloc(sizeof(t_list));
    t_list *node2 = malloc(sizeof(t_list));
    t_list *node3 = malloc(sizeof(t_list));
    <------------------------------------->
    <---------------------------->
    int *x1 = malloc(sizeof(int)); 
    int *x2 = malloc(sizeof(int)); 
    int *x3 = malloc(sizeof(int)); 
    <---------------------------->
    <------>
    *x1=10;
    *x2=40;
    *x3=70;
    <------>
    <------------------->
    node1->data = x1;
    node2->data = x2;
    node3->data = x3;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    <------------------->
    <--------------------------------------->
    printf("total %d\n", ft_list_size(node1));
    
    printf("val1 %d\n", *(int *)node1->data);
    printf("val2 %d\n", *(int *)node2->data);
    printf("val3 %d\n", *(int *)node3->data);
    <--------------------------------------->
    <----------------->
    free(node1);
    free(node2);
    free(node3);
    
    free(x1);
    free(x2);
    free(x3);
    <----------------->
}
*/