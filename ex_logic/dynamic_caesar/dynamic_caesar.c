# include <unistd.h>
# include <stdlib.h>
# include <time.h>

int random_shift(int from, int to)
{
    return rand() % (to - from) + from;
}
void ft_putchar(char c)
{
    write(1, &c, 1);
}
int is_alpha(char c)
{
    if((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
        return 1;
    return 0;
}
char shifting(char c, int shift)
{
    if(shift < 0)
    {
        if((c >= 'A' && c <= 'Z'))
            c -= shift;
        else if((c >= 'a' && c <= 'z'))
            c -= shift;
        else
            c -= shift;
    }
    else
    {
        if((c >= 'A' && c <= 'Z'))
            c += shift;
        else if((c >= 'a' && c <= 'z'))
            c += shift;
        else
            c += shift;
    }
    return c;
}
char turning(char c, int shift)
{
    int i = 26;


    char b = shifting(c, shift);
    while(i && !is_alpha(b))
    {
        b = shifting(b, shift - 1);
        i--;
    }
    return b;
}
char *ft_dynamic_caesar(char *str, int shift)
{
    int i = 0;
    while(str[i])
        i++;

    char *tab = malloc((i + 1) * sizeof(char));
    if(!tab)
        exit(EXIT_FAILURE);
    
    i = 0;
    int j = 0;
    while(str[i])
    {
        if(is_alpha(str[i]))
        {
            tab[j++] = turning(str[i], shift);
        }
        else
            tab[j++] = str[i];
        i++;
    }
    tab[j] = '\0';
    return tab;
}
# include <stdio.h>
int main(int ac, char **av)
{
    if(ac == 2)
    {
        //srand(time(NULL));
        //int shift = random_shift(1, 1000);
        //printf("%d\n", shift);
        int shift = atoi(av[2]);
        char *res = ft_dynamic_caesar(av[1], shift);
        int i = 0;
        while(res[i])
            ft_putchar(res[i++]);
        
        free(res);
    }
    ft_putchar('\n');
    exit(EXIT_SUCCESS); 
}
/*
# include <stdio.h>
int main()
{
    char *res1 = "abcdefghijklmnopqrstuvw21!@xyz";
    char *res2 = "ABCDEFGHIJKLMNOPQRSTU21VWXYZ";
    char *f1 = ft_dynamic_caesar(res1, 100);
    char *f2 = ft_dynamic_caesar(res2, 100);
    printf("%s\n", f1);
    printf("%s\n", f2);
}
*/