int ft_atoi(char *s)
{
    int res;

    res = 0;
    while(*s == 32 || *s == 13)
        s++;
    while(*s == 45 || *s == 43)
        s++;
    while(*s >= '0' && *s <= '9')
    {
        res = res * 10 + (*s) - 48;
        s++;
    }
    return res;
}