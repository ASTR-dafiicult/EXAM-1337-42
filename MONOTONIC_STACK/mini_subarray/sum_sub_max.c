# include <stdio.h>




int max_subarray(int *res, int n)
{
    int sum;
    int max = 0;
    int i = 0;
    int j;
    while(i < n)
    {
        sum = 0;
        j = i;
        while(j < n)
        {
            sum += res[j];
            if(sum > max)
                max = sum;
            j++;
        }
        i++;
    }
    return max;
}
int main()
{
    int res[] = {3, 1, 2, 4};
    printf("%d\n", max_subarray(res, 4));
}