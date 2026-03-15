# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>


int seen_before(int *seen, int nb, int size)
{
    int i = 0;
    while(i < size && (seen[i] != -1))
    {
        if(nb == seen[i])
            return 0;
        i++;
    }
    return 1;
}
int cmp_arr(int nb1, int nb2)
{
    if(nb1 != nb2)
        return 0;
    return 1;
}
int cmp(int *arr1, int *arr2, int size)
{
    int i = 0;
    while(i < size)
    {
        if(!cmp_arr(arr1[i], arr2[i]))
            return 0;
        i++;
    }
    return 1;
}
int solve_array(int *target, int size)
{
    int seen[size];
    seen[0] = -1;
    int arr[size];
    int i = 0;
    while(i < size)
        arr[i++] = 0;

    
    i = 0;
    int j;
    int index = 0;
    int how = 0;
    while(i < size)
    {
        j = i + 1;
        if(!cmp_arr(arr[i], target[i]))
        {
            arr[i] += 1;
        }
        if(cmp_arr(arr[i], target[i]) && seen_before(seen, arr[i], size))
        {
            seen[index++] = arr[i];
            seen[index] = -1;
            how++;
        }
        i++;
        if(i == size)
        {
            if(!cmp(arr, target, size))
            {
                i = 0;
            }
        }
    }
    free(arr);
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