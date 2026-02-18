# include <stdio.h>
# include <stdlib.h>

int length(int *str)
{
    int i = 0;
    while(str[i] != 255)
        i++; 
    return i;
}
int *factorials(int nb)
{
    int *arr = malloc(1024 * sizeof(int));
    arr[0] = 1;
    int size = 1;
    int i = 2;
    int j;
    int rem;
    int pro;
    while(i <= nb)
    {
        j = 0;
        rem = 0;
        while(j < size)
        {
            pro = arr[j] * i + rem;
            arr[j] = pro % 10;
            rem = pro / 10;
            j++;
        }
        if(rem != 0)
        {
            // j will be equal to size
            while(rem)
            {
                arr[size++] = rem % 10;
                rem /= 10;
            }
        }
        i++;
    }
    arr[size] = 255;
    return arr;
}
char *large_factorial(int nb)
{
    int *arr = factorials(nb);
    int len = length(arr);
    char *str = malloc((len + 1) * sizeof(char));
    int i = 0;
    str[len--] = '\0';
    while(len >= 0)
    {
        str[len--] = arr[i++] + 48;
    }
    free(arr);
    return str;
}
int main()
{
    int nb = 25;
    char *res  = large_factorial(nb);
    printf("%s\n", res);
    free(res);
}