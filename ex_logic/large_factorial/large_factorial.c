# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>



char *factorial(int n)
{
    int size = 1;
    int arr[256] = {0};
    arr[0] = 1;
    int i = 2;
    int j;
    int prod;
    int rem;
    while(i <= n)
    {
        j = 0;
        while(j < size)
        {
            prod = arr[j] * i + rem;
            arr[j++] = prod % 10;
            rem = prod / 10;
        }
        while(rem)
        {
            arr[size++] = rem % 10;
            rem /= 10;
        }
        i++;
    }
    char *str = calloc((size + 1), sizeof(char));
    if(!str)
        return NULL;
    str[size] = '\0';
    i = size - 1;
    j = 0;
    while(i >= 0)
    {
        str[i--] = arr[j++] + 48;
    }
    return str;
}
int main()
{
    int n = 25;
    char *res = factorial(n);
    printf("%s\n", res);
}