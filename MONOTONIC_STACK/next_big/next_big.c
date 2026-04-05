# include <unistd.h>
# include <stdlib.h>


int *next_big(int *res, int size, int *size2)
{
    int *stack = malloc(size * sizeof(int));
    int *tab = malloc(size * sizeof(int));
    if(!stack || !tab)
        exit(EXIT_FAILURE);
    
    int i = 0;
    int j = -1;
    while(i < size)
    {
        while(j >= 0 && res[stack[j]] < res[i])
        {
            tab[stack[j--]] = res[i];
        }
        stack[++j] = i;
        i++;
    }
    while(j >= 0)
    {
        tab[stack[j--]] = -1;
    }
    *size2 = i;
    free(stack);
    return tab;
}
int main()
{
    int res[] = {2, 1, 2, 4, 3};
    int size = 5;
    int counter = 0;
    int *tab = next_big(res, size, &counter);
    int i = 0;
    while(i < counter)
    {
        printf("%d ", tab[i++]);
    }
    printf("\n");
}