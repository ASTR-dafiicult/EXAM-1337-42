# ifndef LIST_H
# define LIST_H

typedef struct s_list
{
    int data;
    struct s_list *next;
}t_list;


typedef struct rem{
    void *data;
    struct rem *next;
}rem_list;
#endif