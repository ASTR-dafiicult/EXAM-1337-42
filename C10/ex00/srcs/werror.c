# include <unistd.h>


void error_msg(char *msg)
{
    int i = 0;
    while(msg[i])
    {
        write(2, &msg[i], 1);
        i++;
    }
    write(2, "\n", 1);
}