# include <unistd.h>
# include <stdio.h>


int solve_array(int *arr, int i, int size)
{
    int how = arr[0];
    
    
    if(i == size)
        return how;

    while(i < size)
    {
        if(arr[i] > arr[i - 1])
            how += (arr[i] - arr[i - 1]);
        else
            solve_array(arr, i + 1, size);
        i++;
    }
    return how;
}
int minNumberOperations(int* target, int targetSize)
{
    return solve_array(target, 1, targetSize);   
}
int main()
{
    int arr[] = {94,52,23,39,73,1};
    int size = 6;
    int how = minNumberOperations(arr, size);
    printf("%d\n", how);
}