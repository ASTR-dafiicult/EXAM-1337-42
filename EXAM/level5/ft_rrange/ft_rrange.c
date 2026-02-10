# include <unistd.h>
# include <stdlib.h>


int     *ft_rrange(int start, int end)
{
    int length = 0;
    if(start >= end)
        length = start - end + 1;
    else
        length = end - start + 1;

    int *arr = malloc(length * sizeof(int));
    if(!arr)
        return NULL;
    int i = 0;
    while(i < length)
    {
        arr[i++] = end;
        if(start > end)
            end++;
        else
            end--;
    }
    return arr;
}
/*
# include <stdio.h>
int main()
{  
    int  *arr = ft_rrange(10, -5);
    int len = 10 - (-5) + 1;
    int i = 0;
    while(i < len)
        printf("%d  ", arr[i++]);
    
    printf("\n");
}
*/