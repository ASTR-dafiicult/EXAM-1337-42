# include <unistd.h>
# include <stdio.h>


int		max(int* tab, unsigned int len)
{
    int max;
    if(!len)
        return 0;
    max = tab[0];
    while(--len)
    {
        if(max < tab[len])
            max = tab[len];
    }
    return max;
}
int main()
{
    int arr[] = {1, 22, 31, 14, 350, 60, 7, 18, 92};
    printf("%d\n", max(arr, 9));
}