# include "../includes/libcat.h"

void ft_cat(char *program_name, char *file_name)
{
    char buff[30000]; // less then 30 ko
    int bytes;
    int fd;
    fd = open(file_name, O_RDONLY);
    if(fd == -1)
    {
        ft_putstr(program_name);
        ft_putstr(": ");
        ft_putstr(basename(file_name));
        ft_putstr(strerror(errno));
        write(2, "\n", 1);
        return;
    }
    while((bytes = read(fd, buff, 30000)) > 0)
    {
        write(1, buff, bytes);
    }
    write(1, "\n", 1);
}