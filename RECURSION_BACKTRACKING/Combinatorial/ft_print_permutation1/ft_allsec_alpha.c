# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>


void ft_putstr(char *str, int len)
{
    write(1, str, len);
    write(1, "\n", 1);
}
void    generate_perm(char *str, int index, int len)
{
    if(index == len)
    {
        str[index] = '\0';
        ft_putstr(str, len);
        return;
    }
    str[index]= 'a';
    if(index < len)
        generate_perm(str, index + 1, len);
    
    str[index] = 'b';
    if(index < len)
        generate_perm(str, index + 1, len);
}
int main()
{
    int k = 10;
    char *str = calloc((k + 1), sizeof(char));
    generate_perm(str, 0, k);
}

// aaa
// aab
// aba
// abb
// baa
// bab
// bbb