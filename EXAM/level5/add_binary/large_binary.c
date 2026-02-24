# include <stdlib.h>
# include <unistd.h>

void    ft_putstr(char *str)
{
    int i = 0;
    while(str[i])
        write(1, &str[i++], 1);

    write(1, "\n", 1);
}
int     ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
        i++;
    return i;
}
char    *reverse_str(char *tab)
{
    int len = ft_strlen(tab);
    char *rev = malloc((len + 1) * sizeof(char));
    if(!rev)
        exit(EXIT_FAILURE);
    int i = len - 1;
    int j = 0;
    while(i >= 0)
    {
        rev[j++] = tab[i--];
    }
    rev[j] = '\0';
    return rev;
}
char*   addBinary(char* a, char* b)
{
    if((a[0] == '0' && a[1] == '\0') && (b[0] == '0' && b[1] == '\0'))
    {
        char *err = malloc(2);
        err[0] = '0';
        err[1] = '\0';
        return err;
    }



    int i = ft_strlen(a) - 1;
    int j = ft_strlen(b) - 1;

    char *res = malloc(2000);
    if(!res)
        exit(EXIT_FAILURE);
    int carry = 0;
    int sum;
    int k = 0;
    while(i >= 0 || j >= 0 || carry)
    {
        sum = carry;
        if(i >= 0)
            sum += a[i--] - '0';
        if(j >= 0)
            sum += b[j--] - '0';
        res[k++] = sum % 2 + '0';
        carry = sum / 2;
    }
    res[k] = '\0';
    char *res2 = reverse_str(res);
    return res2;
}
int     main()
{
    //char *a = "10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101";
    //char *b = "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011";
    
    char *a = "11";
    char *b = "1";
    char *res = addBinary(a, b);
    ft_putstr(res);
    free(res);
}