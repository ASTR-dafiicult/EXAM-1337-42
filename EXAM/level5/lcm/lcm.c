# include <unistd.h>



unsigned int    lcm(unsigned int a, unsigned int b)
{
    if(a == 0 || b == 0)
        return 0;
    unsigned int val1 = a;
    unsigned int val2 = b;
    unsigned int rem = 0;

    while((rem = val1 % val2) != 0)
    {
        val1 = val2;
        val2 = rem;
    }
    return ((a * b) / val2);
}
/*
# include <stdio.h>
int main()
{
    unsigned int res = lcm(42, 0);
    printf("%u\n", res);
}
*/