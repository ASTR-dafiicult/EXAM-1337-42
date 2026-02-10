# include <unistd.h>

long zeros(long n)
{
    long counter = 0;
    while(n >= 5)
    {
        n /= 5;
        counter += n;
    }
    return counter;
}
# include <stdio.h>
int main()
{
    long nb = 30;
    printf("%ld\n", zeros(nb));
}
