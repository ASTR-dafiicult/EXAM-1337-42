# include <stdio.h>
# include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}
void ft_putnbr(int nb)
{
    if(nb < 0)
    {
        ft_putchar('-');
        nb = -nb;
    }
    if(nb > 9)
        ft_putnbr(nb / 10);
    ft_putchar((nb % 10) + 48);
}
long long power(long long nb, int ouss)
{
    if(ouss == 0)
        return 1;
    return nb *= power(nb, ouss - 1);
}
long long hashing(char *s, int from, int to)
{

    long long res_hash = 0;
    int j = 0;          // (exponent, always starts at 0)
    int i = from;
    int base = 31;
    while(i <= to)
    {
        res_hash += s[i] * power(base, j);
        j++;
        i++;
    }
    return res_hash;
}
int check_hash(long long *hashs, long long h, int size)
{
    int i = 0;
    while(i < size)
    {
        if(hashs[i] == h)
            return 0;
        i++;
    }
    return 1;
}
int count_unique_substrings(char *s)
{
    int len = 0;
    while(s[len])
        len++;

    long long his_hash[len * (len + 1) / 2];
    int count = 0;
    int idx = 0;
    int i = 0;
    int j;
    while(s[i])
    {
        j = i;
        while(s[j])
        {
            long long h = hashing(s, i, j);
            if(check_hash(his_hash, h, idx))
            {
                his_hash[idx++] = h;
                count++;
            }
            j++;
        }
        i++;
    }
    return count;
}
int main(int ac, char **av)
{
    if(ac == 2)
    {
        ft_putnbr(count_unique_substrings(av[1]));
    }
    ft_putchar('\n');   
}