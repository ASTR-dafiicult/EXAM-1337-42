# include <unistd.h>


unsigned int    lcm(unsigned int a, unsigned int b)
{
    //GCD
    unsigned int rem = 0;
    unsigned int val1 = a;
    unsigned int val2 = b;
    if(a == 0 || b == 0)
    {
        return 0;
    }
    if(val1 == val2)
    {
        return val1;
    }
    while(val2 != 0)
    {
        rem = val1 % val2;
        val1 = val2;
        val2 = rem;
    }
    //LCM
    return ((a * b) / val1);
}
/*
# include <stdio.h>
int main()
{
    unsigned int val_lcm = lcm(42, 12);
    printf("%d\n", val_lcm);
}
    */