#include "libdoop.h"

int main(int ac, char **av)
{
    if(ac == 4)
    {
        int val1 = ft_atoi(av[1]);
        int val2 = ft_atoi(av[3]);
        int op = check_op(av[2][0]);
        printf("%d\n", op);
        if(av[2][1] != '\0')
        {
            write(1, "\n", 1);
            return 0;
        }
        if(op == 43 || op == 45 || op == 47 || op == 37 || op == 42)
        {
            if(op == 43)
                printf("%d\n", val1 + val2);
            if(op == 45)
                printf("%d\n", val1 - val2);
            if(op == 42)
                printf("%d\n", val1 * val2);
            if(op == 47)
                printf("%d\n", val1 / val2);
            if(op == 37)
                printf("%d\n", val1 % val2);
        }
        else{
            write(1, "\n", 1);
            return 0;
        }
        return 0;
    }
    write(1, "\n", 1);
}