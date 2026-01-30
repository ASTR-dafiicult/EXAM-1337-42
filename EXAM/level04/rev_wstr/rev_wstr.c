# include <unistd.h>
# include <stdlib.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}
int blank(char c)
{
    if(c == 32 || c == 9)
        return 0;
    return 1;
}
void putstr(char *str)
{
    int i = 0;
    while(str[i] && blank(str[i]))
        ft_putchar(str[i++]);
}
int counter(char *str)
{
    int counter = 0;
    int i = 0;
    while(str[i])
    {
        
        if(blank(str[i]))
        {
            if(i == 0 || !blank(str[i - 1]))
                counter++;
        }
        i++;
    }
    return counter;
}
int length_string(char *str)
{
    int length = 0;
    while(str[length] && blank(str[length]))
        length++;
    
    return length;
}
char *copy_string(char *str, int length)
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
        int index = 0;
        int size = 0;
        int length = counter(av[1]);
        char **str = malloc((length + 1) * sizeof(char *));
        if(!str)
            return 0;
        
        int i = 0;
        while(av[1][i])
        {
            if(blank(av[1][i]))
            {
                size = length_string(&av[1][i]);
                str[index] = copy_string(&av[1][i], size); 
                if(!str[index])
                {
                    int j = 0;
                    while(index > j)
                    {
                        free(str[j++]);
                    }
                    return 0;
                } 
                index++;
                i += size;
            }
            else
                i++;
        }
        str[index] = NULL;
        i = 0;
        while(i < length)
        {
            putstr(str[--length]);
            if(i != length)
                ft_putchar(' ');
        }
        ft_putchar('\n');
        i = 0;
        while(str[i])
        {
            free(str[i++]);//remove allocated space
        }
        free(str);//releases the memory
        return 0;
    }
    ft_putchar('\n');
}