# include <stdio.h>
# include <stdlib.h>


int power(int nb, int pow)
{
    if(pow == 0)
        return 1;
    return nb *= power(nb, pow - 1);
}
int hashing(char *s, int from, int to)
{
    int res_hash = 0;
    int base = 131;
    int j = 0;
    while(from < to)
    {
        res_hash += s[from] * power(base, j);
        j++;
        from++;
    }
    return res_hash;
}
int *find_pattern(char *text, char *pattern, int *returnSize)
{
    int text_len = 0;
    while(text[text_len]) text_len++;

    int pat_len = 0;
    while(pattern[pat_len]) pat_len++;

    int *res = malloc(text_len * sizeof(int));
    
    int hash = hashing(pattern, 0, pat_len);
    
    int i = 0;
    int new_hash = 0;
    int index = 0;
    while(text[i])
    {
        if(text[i + pat_len - 1])
        {
            new_hash = hashing(text, i, pat_len + i);//aba  abcaba
            if(hash == new_hash)
            {
                res[index++] = i;
            }
        }
        i++;
    }
    *returnSize = index;
    return res;
}
int main()
{
    char *str = "ababcababa";
    char *pat = "aba";
    int c = 0;
    int *res = find_pattern(str, pat, &c);

    int i = 0;
    while(i < c)
    {
        printf("%d ", res[i++]);
    }
    printf("\n");
}