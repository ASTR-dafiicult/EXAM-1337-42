# include <stdio.h>
# include <stdlib.h>


int largestRectangleArea(int* heights, int heightsSize)
{
    int *stack = calloc(heightsSize, sizeof(int));
    if(!stack)
        exit(EXIT_FAILURE);
    
    int number;
    int res;
    int max;
    int width;
    int index;
    int j = -1;
    int i = 0;
    while(i < heightsSize)
    {
        while(j >= 0 && heights[stack[j]] > heights[i])
        {
            number = heights[stack[j--]];
            index = (j >= 0) ? stack[j] : -1; 
            width = i - index - 1;
            res = number * width;
            if(res > max)
                max = res;
        }
        stack[++j] = i;
        i++;
    }
    while(j >= 0)
    {
        number = heights[stack[j--]];
        index = (j >= 0) ? stack[j] : -1;
        width = heightsSize - index - 1;
        res = number * width;
        if(res > max)
            max = res;
    }
    free(stack);
    return max;

}
int main()
{
    // int res[] = {2, 1, 5, 6, 2, 3};
    int res[] = {2, 1, 2};
    // int res[] = {4, 2};
    // int res[] = {2, 4};
    // int res[] = {1};
    // int res[] = {5, 4, 1, 2};
    int size = 3;

    int nb = largestRectangleArea(res, size);
    printf("%d\n", nb);
}