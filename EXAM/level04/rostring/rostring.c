# include <unistd.h>
# include <stdlib.h>


void ft_putchar(char c)
{
    write(1, &c, 1);
}
void ft_putstr(char *str)
{
    int i = 0;
    while(str[i])
        ft_putchar(str[i++]);
}
int blank(char c)
{
    if(c == 32 || c == 9)
    {
        return 0;
    }
    return 1;
}
int length_word(char *str)
{
    int i = 0;
    while(str[i] && blank(str[i]))
    {
        i++;
    }
    return i;
}
char *copy_word(char *str, int length)
{
    int i = 0;
    char *tab = malloc((length + 1) * sizeof(char));
    if(!tab)
        return NULL;
    while(i < length)
    {
        tab[i] = str[i];
        i++;
    }
    tab[i] = '\0';
    return tab;
}
int main(int ac, char **av)
{
    if(ac == 2)
    {
        int size;
        int access = 1;
        int i = 0;
        int j = 0;
        char **str = malloc(2 * sizeof(char *));
        while((av[1][i] && access) || (!blank(av[1][i])))
        {
            if(blank(av[1][i]))
            {
                size = length_word(&av[1][i]);
                str[j] = copy_word(&av[1][i], size);
                if(!str[j])
                {
                    free(str[j]);
                    ft_putchar('\n');
                    return 0;
                }
                i += size;
                j++;
                access = 0;
            }
            else
                i++;
        }
        str[j] = NULL;
        access = 0;
        while(av[1][i])
        {
            if(blank(av[1][i]))
            {
                ft_putchar(av[1][i]);
            }
            if(blank(av[1][i]) && av[1][i + 1] == '\0')
            {
                ft_putchar(' ');
            }
            if(access)
            {
                ft_putchar(av[1][i]);
                access = 0;
            }
            else if(blank(av[1][i]) && !blank(av[1][i + 1]))
            {
                access = 1;
            }
            i++;
        }
        i = 0;
        j = 0;
        while(str[i])
        {
            ft_putstr(str[i++]);
        }
        free(str[0]);
        free(str);
    }
    ft_putchar('\n');
    return 0;
}