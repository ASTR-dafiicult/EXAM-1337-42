# include <unistd.h>
# include <stdlib.h>


int check_char(char c, char *str)
{
    int i = 0;
    int count = 0;
    while(str[i])
    {
        if(c == str[i])
            count++;
        i++;
    }
    return count;
}
char *non_repeat(char *str)
{
    int len = 0;
    while(str[len])
        len++;
    char *tab = malloc((len + 1) * sizeof(char));
    if(!tab)
        return NULL;
    
    int i = 0;
    int size = 0;
    int j = 0;
    while(str[i])
    {
        int val = check_char(str[i], str);
        if(val == 1)
        {
            tab[j++] = str[i];
        }
        i++;
    }
    tab[j] = '\0';
    return tab;
}
int main(int ac, char **av)
{
    if(ac == 2)
    {
        char *res = non_repeat(av[1]);
        int i = 0;
        while(res[i])
            write(1, &res[i++], 1);
    }
    write(1, "\n", 1);
    return 0;
}