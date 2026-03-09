# ifndef FT_LIST_H
# define FT_LIST_H

typedef struct    ListNode
{
    struct ListNode *next;
    int             val;
}                 ListNode;
#endif