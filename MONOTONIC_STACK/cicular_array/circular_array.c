# include <stdlib.h>
# include <stdio.h>


int *circular_array(int *nums, int size, int *resize)
{
    int *stack = calloc(size, sizeof(int));
    int *res = malloc(size  * sizeof(int));
    if(!stack || !res)
        exit(EXIT_FAILURE);

    int i = 0;
    int k = 0;
    int j = -1;
    int max = 0;
    int fake_index = 0;
    while(k < size * 2)
    {
        while(j >= 0 && nums[stack[j]] < nums[i % size])
        {
            res[stack[j--]] = nums[i % size];
        }
        if(k < size)
            stack[++j] = i;
        i++;
        k++;
    }
    while(j >= 0)
    {
        res[stack[j--]] = -1;
    }
    *resize = size;
    return res;
}
int main()
{
    int arr[] = {1, 2, 10, 1, 2};
    int c = 0;
    int *res = circular_array(arr, 5, &c);
    int i = 0;
    while(i < c)
    {
        printf("%d ", res[i++]);
    }
    printf("\n");
}