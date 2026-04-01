# include <stdlib.h>
# include <stdio.h>


int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize)
{
    int *stack = calloc(temperaturesSize, sizeof(int));//////0
    int *res = calloc(temperaturesSize, sizeof(int));
    if(!stack || !res)
        exit(EXIT_FAILURE);
    int i = 0;
    int j = -1;
    while(i < temperaturesSize)
    {
        while(j >= 0 && temperatures[stack[j]] < temperatures[i])
        {
            res[stack[j]] = i - stack[j];
            j--;
        }
        stack[++j] = i;
        i++;
    }
    free(stack);
    *returnSize = i;
    return res;
}
int main()
{
    int tmp[] = {73,74,75,71,69,72,76,73}; //55,38,53,81,61,93,97,32,43,78
    int size = 8;
    int c = 0;
    int *res = dailyTemperatures(tmp, size, &c);
    int i = 0;
    while(i < c)
    {
        printf("%d ", res[i++]);
    }
    printf("\n");
    free(res);
}
//30,60,90
//73,74,75,71,69,72,76,73
//30,40,50,60