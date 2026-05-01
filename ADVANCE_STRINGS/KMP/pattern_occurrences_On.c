# include <stdio.h>
# include <stdlib.h>


int power(int nb, int pow)
{
    if(pow == 0)
        return 1;
    return nb *= power(nb, pow - 1);
}
int hashing(char *str, int *base, int from, int to)
{
    int res_hash = 0;
    int j = 0;
    while(from < to)
    {
        res_hash += str[from] * power(*base, j);
        j++;
        from++;
    }
    return res_hash;
}
int *find_pattern(char *text, char *pattern, int *returnSize)
{
    int pat_len = 0;
    while(pattern[pat_len]) pat_len++;
    int text_len = 0;
    while(text[text_len]) text_len++;
    /////

    int *res_idx = malloc(text_len * sizeof(int));
    if(!res_idx)
        exit(EXIT_FAILURE);

    int i = 0;
    int index = 0;
    int base = 131;
    int win_hash = hashing(text, &base, 0, pat_len);
    int pat_hash = hashing(pattern, &base, 0, pat_len);

    while(i <= text_len - pat_len)//no out of bound ---> (i <= text_len - pat_len)
    {
        if(win_hash == pat_hash)
        {
            res_idx[index++] = i;
        }
        //"a b a b c a b a b a"
        //update formula hash delete 'a' and add 'b' and count hash from ('1' to '3' "text[i + pat_len]")
        win_hash = (win_hash - text[i] * power(base, pat_len - 1)) * base + text[i + pat_len];
        i++;
    }
    *returnSize = index;
    return res_idx;
}
int main()
{
    char *s = "ababcababa";
    char *pat = "aba";
    int len = 0;
    int *res = find_pattern(s, pat, &len);
    int i = 0;
    while(i < len)
    {
        printf("%d ", res[i++]);
    }
    printf("\n");
    free(res);
}