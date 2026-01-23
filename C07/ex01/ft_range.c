# include "stdlib.h"


int *ft_range(int min, int max)
{
    int length;
    int *tab;
    
    if(min >= max)
    {
        return (NULL);
    }
    length = max - min; //else
    tab = malloc(length * sizeof(int));
    int i = 0;
    while(i < length)
    {
        tab[i] = min++;
        i++;
    }
    return tab;
}
# include "stdio.h"
int main()
{
    int min = -4;
    int max = 6;
    int *tab = ft_range(min, max);
    int length = max - min;
    int i = 0;
    while(i < length)
    {
        printf("%d ", tab[i]);
        i++;
    }
    printf("\n");
    free(tab);
}