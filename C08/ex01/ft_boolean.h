# include "unistd.h"

# define EVEN_MSG "I have an even number of arguments."
# define ODD_MSG "I have an odd number of arguments."
# define SUCCESS 0

typedef enum
{
    TRUE=1,
    FALSE=0
}t_bool;

int EVEN(int nbr)
{
    if(nbr % 2 == 0)
    {
        return 1;
    }
    else{
        return 0;
    }
}