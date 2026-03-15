# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>


int cmp_arr(int nb1, int nb2)
{
   if(nb1 > nb2)
        return 1;
    return 0;
}
int solve_array(int *target, int size)
{
   
    int i = 0;
    int j;
    int how = target[0];
    while(i < size)
    {
        j = i + 1;
        if(j < size && cmp_arr(target[j], target[i]))
        {
            how += (target[j] - target[i]);
        }   
        i++;
    }
    return how;
}
int minNumberOperations(int* target, int targetSize)
{
    return solve_array(target, targetSize);
}

int main()
{
    int arr[] = {3,1,5,4,2};
    int size = 5;
    int how = minNumberOperations(arr, size);
    printf("%d\n", how);
}