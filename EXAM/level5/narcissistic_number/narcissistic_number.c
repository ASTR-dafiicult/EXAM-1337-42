# include <stdio.h>
# include <stdbool.h>
# include <math.h>

bool narcissistic(int num)
{
    if(num <= 0)
        return false;
    int size = 0;
    int tmp = num;
    int nbr = num;
    int res = 0;
    int t;
    int nb;
    while(tmp)
    {
        tmp /= 10;
        size++;
    }
    int i = 0;
    while(i < size)
    {
        nb = num % 10;
        t = pow(nb, size);
        res += t;
        num /= 10;
        i++;
    }
    if(res == nbr)
        return true;
    return false;
}
/*
int main()
{
    bool res = narcissistic(1652);
    if(res)
        printf("narcissistic\n");
    else
        printf("not narcissistic\n");
}
*/