# include <unistd.h>
# include <stdlib.h>

int     *ft_range(int start, int end)
{
    int i = 0;
    int length;
    int *tab;
    if(start <= end)
        length = end - start + 1;
    else
        length = start - end + 1;
   
    if(!(tab = (int *)malloc(length * sizeof(int))))
    {
        return NULL;
    } 
    while(i < length)
    {
        tab[i] = start;
        if(start > end)
            start--;
        else
            start++;

        i++;
    }
    return tab;
}
/*
# include <stdio.h>
int main()
{
    int start = 1;
    int end = -3;
    int length = 0;
    int *tab = ft_range(start, end);
    int i = 0;

    if(start <= end)
    {
        length = end - start + 1;
    }
    if(end < start)
    {
        length = start - end + 1;
    }

    while(i < length)
    {
        printf("%d ", tab[i]);
        i++;
    }
    printf("\n");
}
*/