# include <unistd.h>
# include "lib.h"

int main(int ac, char **av)
{
    if(ac < 2)
    {
        error_msg("File name missing.");
        return 0;
    }
    if(ac > 2)
    {
        error_msg("Too many arguments.");
        return 0;
    }
    else{
        display_file(av[1]);
        write(1, "\n", 1);
    }
    return 0;
}