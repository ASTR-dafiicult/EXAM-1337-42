# include <stdio.h>


unsigned million_febonacci(unsigned number)
{
    unsigned int first = 0;
    unsigned int sec = 1;
    unsigned int  next = 0;
    unsigned int sum = 0;
    unsigned int i = 0;
    while(number > i)
    {
        next = sec + first;
        first = sec;
        sec = next;
        if(next % 2 == 0)
            sum += next;
        i+=first;
    }
    return sum;
}
int main()
{
    unsigned int total = million_febonacci(4000000);
    printf("%u\n", total);
}