# include <fcntl.h>
# include <unistd.h>

void display_file(char *filename)
{
    int fd;
    char buff;
    fd = open(filename, O_RDONLY);
    if(fd == -1)
    {
        write(2, "Cannot read file.", 17);
        return;
    }
    while(read(fd, &buff, 1) > 0)
    {
        write(1, &buff, 1);
    }
    close(fd);
}