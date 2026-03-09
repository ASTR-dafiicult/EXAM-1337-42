# include <unistd.h>
# include <stdlib.h>


int *ft_interval(int start, int end)
{
    if(start > end || start == end)
        return NULL;
    
    int len = end - start;

    int *tab = malloc(len);
    if(!tab)
        return NULL;
    
    int i = 0;
    while(i < len)
    {
        tab[i++] = start++;
    }
    return tab;
}
# include <stdio.h>
int main()
{
    int start = 7;
    int end = 2;

    int len = end - start;
    int *res = ft_interval(start, end); 
    int i = 0;
    while(i < len)
    {
        printf("%d ", res[i++]);
    }
    printf("\n");
    // ft_interval(3, 7)	{3, 4, 5, 6}
}