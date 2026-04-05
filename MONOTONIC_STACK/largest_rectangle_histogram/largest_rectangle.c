# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>


int largestRectangleArea(int* heights, int heightsSize)
{
    int nb1 = 0;
    int nb2 = 0;
    int left;
    int i = 0;
    while(i < heightsSize)
    {
        if(i == 0)
            left = 0;
        else
            left = i - 1;
        int right = i + 1;
        int count = 1;
       
        while(left >= 0 && right < heightsSize && heights[i] <= heights[right])
        {
            right++;
            count++;
        }
        while(left >= 0 && heights[i] < heights[left])
        {
            left--;
            count++;
        }
        nb1 = heights[i] * count;
        if(nb1 > nb2)
        {
            nb2 = nb1;
        }
        i++;
    }
    return nb2;
}
int main()
{
    // int res[] = {2, 1, 5, 6, 2, 3};
    // int res[] = {2, 1, 2};
    int res[] = {2, 2};
    // int res[] = {5,4,1,2};
    int size = 2;

    int nb = largestRectangleArea(res, size);
    printf("%d\n", nb);
}