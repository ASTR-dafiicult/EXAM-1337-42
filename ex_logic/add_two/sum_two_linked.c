# include "linked_node.h"
# include <stdio.h>
# include <stdlib.h>


ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    ListNode *head = malloc(sizeof(ListNode));
    head->next = NULL;

    ListNode *tail = head;
    int sum = 0;
    int carry = 0;
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
        
        tail->next = new;
        tail = new;

        if(l1)
        l1 = l1->next;
        if(l2)
        l2 = l2->next;
    }
    return head->next;
}
void print_list(ListNode *node)
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
    print_list(res);
}






