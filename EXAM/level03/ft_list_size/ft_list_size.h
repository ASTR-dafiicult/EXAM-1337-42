# ifndef LIST_SIZE
# define LIST_SIZE

# include <unistd.h>

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}t_list;

#endif