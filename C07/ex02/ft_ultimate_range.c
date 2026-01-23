# include "stdlib.h"


int    ft_ultimate_range(int **range, int min, int max)
{
    int *tab;
    int length;
    
    if(min >= max)
    {
        return (0);
    }
    length = max - min;
    tab = malloc(length * sizeof(int));
    
    if(tab == NULL)
    {
        return (0);
    }
    int i = 0;
    while(i < length)
    {
        tab[i] = min++;
        ++i;
    }
    *range = tab;
    return length;
}
# include "stdio.h"
int main()
{
    int *arr;
    int size = ft_ultimate_range(&arr, 2, 5);//min / max
    printf("size = %d\n", size);
    int i = 0;
    while(i < size)
    {
        printf("%d ", arr[i]);
        i++;
    }
    printf("\n");
    free(arr);
}