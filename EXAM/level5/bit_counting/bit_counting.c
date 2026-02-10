# include <unistd.h>


size_t countBits(unsigned value)
{
    if(value <= 0)
        return 0;
    char base[] = "01";
    int counter = 0;
    char str[256] = {0};
    int i = 0;
    while(value)
    {
        str[i++] = base[value % 2];
        value /= 2;
    }
    i = 0;
    while(str[i])
    {
        if(str[i++] == '1')
            counter++;
    }
    return counter;
}
# include <stdio.h>
int main()
{
    size_t res = countBits(4);
    printf("%ld\n",  res);
}