# include <stdio.h>


int power(int nb, int pow)
{
    if(pow == 0)
        return 1;
    nb *= power(nb, pow - 1);

    return nb;
}
int main()
{
    int nb = 5;
    int pow = 3;
    printf("%d\n", power(nb, pow));
}