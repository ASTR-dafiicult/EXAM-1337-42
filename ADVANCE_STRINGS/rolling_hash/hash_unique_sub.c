int power(int nb, int pow)
{
    if(pow == 0)
        return 1;
    return nb *= power(nb, pow - 1);
}
int hashing(char *s, int from , int to)
{
    int base = 131;
    int res_hash = 0;
    int j = 0;
    while(from <= to)
    {
        res_hash += s[from] * power(base, j);
        j++;
        from++;
    }
    return res_hash;
}
int check_hash(int *hashs, int new, int size)
{
    int i = 0;
    while(i < size)
    {
        if(new == hashs[i])
            return 0;
        i++;
    }
    return 1;
}
int count_unique_substrins(char *s)
{
    int len = 0;
    while(s[len]) len++;

    int hashs[len * (len + 1) / 2];
    int count = 0;
    int idx = 0;
    int i = 0;
    int j;
    while(s[i])
    {
        j = i;
        while(s[j])
        {
            int hash = hashing(s, i, j);
            if(check_hash(hashs, hash, idx))
            {
                hashs[idx++] = hash;
                count++;
            }
            j++;
        }
        i++;
    }
    return count;
}
# include <stdio.h>
int main()
{
    printf("%d\n", count_unique_substrins("bab"));
}