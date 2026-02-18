# include <unistd.h>


int find_outlier(const int values[], size_t count)
{
    size_t i = 0;
    int nb;
    int even = 0;
    int odd;
    while(i < count)
    {
        if(values[i] % 2 != 0)
            odd++;
        else
            even++;
        i++;
    }
    if(odd > even)
    {
        i = 0;
        while(i < count)
        {
            if(values[i] % 2 == 0)
            {
                nb = values[i];
                return nb;
            }
            i++;
        }
    }
    else{
        i = 0;
        while(i < count)
        {
            if(values[i] % 2 != 0)
            {
                nb = values[i];
                return nb;
            }
            i++;
        }
    }
    return 0;
}
/*
# include <stdio.h>
int main()
{
    int arr[] = {160, 3, 1719, 19, 11, 13, -21};
    int count = 7;
    printf("%d\n", find_outlier(arr, count));
}
    */