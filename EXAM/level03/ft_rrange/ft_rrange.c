//# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>


void    ft_putchar(char c)
{
    write(1, &c, 1);
}
int     *ft_rrange(int start, int end)
{
    int length;
    int i;
    int *arr;
    if(start > end)
        length = (start - end + 1);
    else
        length = (end - start + 1);

    if(!(arr = (int *)malloc(length * sizeof(int))))
    {
        return (NULL);
    }
    i = 0;
    while(i < length)
    {
        arr[i] = end;
        if(start < end)
            end--;
        else
            end++;
        i++;
    }
    return arr;
}
/*
int     main()
{
    int start = 0;
    int end = -3;
    int *res = ft_rrange(start, end);
    int length;
    int i = 0;

    if(start > end)
        length = (start - end + 1);
    else
        length = (end - start + 1);
    while(i < length)
    {
        printf("%d  ", res[i]);
        i++;
    }
    printf("\n");
    free(res);
}
*/