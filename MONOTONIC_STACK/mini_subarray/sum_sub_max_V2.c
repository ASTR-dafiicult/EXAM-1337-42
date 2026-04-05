# include <stdlib.h>
# include <stdio.h>


int sum_sub_max(int *res, int size)
{
    int current = res[0];
    int global = res[0];
    int i = 1;
    while(i < size)
    {
        current = (res[i] + current > res[i]) ? current + res[i] : res[i];
        global = (current > global) ? current : global;
        i++;
    }
    return global;
}
int main()
{
    int arr[] = {1, 2, 3, 4};
    printf("%d\n", sum_sub_max(arr, 4));
}


