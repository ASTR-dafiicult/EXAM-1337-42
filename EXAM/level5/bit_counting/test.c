# include <stdio.h>



size_t countBits(unsigned value)
{
    if(value < 0)
        return 0;
    unsigned i = 8192;
    char str[256] = {0};
    int con = 0;
    int j = 0;
    while(i)
    {
        if(value / i != 0)
        {
            str[j++] = '1';
            value -= i;
        }
        else
            str[j++] = '0';
        i /= 2;
    }
    str[j] = '\0';
    j = 0;
    while(str[i])
    {
        if(str[i] == '1')
            con++;
        i++;
    }
	return con;
}
int main()
{
    size_t res = countBits(4);
    printf("%ld\n", res);
}