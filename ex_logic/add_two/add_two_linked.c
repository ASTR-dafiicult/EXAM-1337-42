# include <stdlib.h>
# include <stdio.h>
# include "linked_node.h"


//Definition for singly-linked list.
ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    ListNode *node1 = malloc(sizeof(ListNode));
    node1->next = NULL;
    ListNode *node2 = node1;

    int carry = 0;
    int sum;
    int val1;
    int val2;
    while(l1 || l2 || carry)
    {
        if(l1->val)
            val1 = l1->val;
        if(l2->val)
            val2 = l2->val;
        sum = val1 + val2 + carry;
        ListNode *new = malloc(sizeof(ListNode));
        new->val = sum % 10;
        new->next = NULL;
        carry = sum / 10;

        node2->next = new;
        node2 = new;
        if(l1)
            l1 = l1->next;
        if(l2)
            l2 = l2->next;
    }
    return node1->next;
}
//node1	dummy	dummy	dummy	dummy
//node2	dummy	node7	node0	node8
//node1->next	NULL	node7	node7->0	node7->0->8
void print(ListNode *node)
{
    while(node)
    {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");
}
int main()
{
    ListNode *l1 = malloc(sizeof(ListNode));
    l1->val = 2;
    l1->next = malloc(sizeof(ListNode));
    l1->next->val = 4;
    l1->next->next = malloc(sizeof(ListNode));
    l1->next->next->val = 3;
    l1->next->next->next = NULL;

    ListNode *l2 = malloc(sizeof(ListNode));
    l2->val = 5;
    l2->next = malloc(sizeof(ListNode));
    l2->next->val = 6;
    l2->next->next = malloc(sizeof(ListNode));
    l2->next->next->val = 4;
    l2->next->next->next = NULL;

    ListNode *res = addTwoNumbers(l1, l2);
    print(res);
    
    free(res);  
    free(l1->next);
    free(l2->next);
}