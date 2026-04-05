# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>


int *next_small(int *nums, int size, int *re_size)
{
    int *stack = malloc(size * sizeof(int));
    int *res = malloc(size * sizeof(int));
    if(!res || !stack)
        exit(EXIT_FAILURE);

    int i = 0;
    int j = -1;
    while(i < size)
    {
        while(j >= 0 && nums[stack[j]] > nums[i])
        {
            res[stack[j--]] = nums[i];
        }
        stack[++j] = i;
        i++;
    }
    while(j >= 0)
    {
        res[stack[j--]] = -1;
    }
    free(stack);
    *re_size = i;
    return res;
}
int main()
{
    int res[] = {1, 3, 2, 4, 3};
    int count = 0;
    int *res2 = next_small(res, 5, &count);
    int i = 0;
    while(i < count)
    {
        printf("%d ", res2[i++]);
    }
    printf("\n");
    free(res2);
}