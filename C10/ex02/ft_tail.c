# include "lib_tail.h"

void ft_tail(char *file, char *program)
{
    int i;
    int fd;
    int total;
    int bytes;
    int start;
    int count;
    char buff[30000];

    fd = open(file, O_RDONLY);
    if(fd == -1)
    {
        ft_putstr(program);
        write(2, ": ", 2);
        ft_putstr("cannot open '");
        ft_putstr(basename(file));
        ft_putstr("' for reading: ");
        ft_putstr(strerror(errno));
        write(1, "\n", 1);
        return;
    }
    total = 0;
    //read ---> to end
    while ((bytes = read(fd, buff + total, 1)) > 0)
        total++;

    count = 0;    
    //back to 10
    i = total - 1;
    while (i >= 0)
    {
        if (buff[i] == '\n')
            count++;
        if (count == 10)
            break;
        i--;
    }

    //start point
    if (i < 0)
        start = 0;
    else
        start = i + 1;
    write(1, buff + start, total - start);
}