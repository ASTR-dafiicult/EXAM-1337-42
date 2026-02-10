# include <unistd.h>
# include <stdlib.h>

void putstr(char *str)
{
    int i = 0;
    while(str[i] && (str[i] != 32 && str[i] != 9))
        write(1, &str[i++], 1);
}
int count_word(char *str)
{
    int i = 0;
    int counter = 0;
    while(str[i])
    {
        if(str[i] != 32 && str[i] != 9)
        {
            if(i == 0 || (str[i - 1] == 9 || str[i - 1] == 32))
                counter++;
        }
        i++;
    }
    return counter;
}
int length_word(char *str)
{
    int i = 0;
    while((str[i] != 32 && str[i] != 9) && str[i])
        i++;
    return i;
}
char *copy(char *str, int length)
{
    int i = 0;
    char *tab = malloc(length + 1);
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
        int i = 0;
        int size = count_word(av[1]);
        int length;
        int index = 0;
        char **str = malloc((size + 1) * sizeof(char *));
        if(!str)
        {
            write(1, "\n", 1);
            return 0;
        }
        while(av[1][i])
        {
            if(av[1][i] != 32 && av[1][i] != 9)
            {
                length = length_word(&av[1][i]);
                str[index] = copy(&av[1][i], length);
                if(!str[index])
                {
                    int j = 0;
                    while(j < index)
                        free(str[j++]);
                    return 0;
                }
                index++;
                i += length;
            }
            else
                i++;
        }
        str[index] = NULL;
        i = 0;
        while(i < index)
        {
            putstr(str[--index]);
            if(i != index)
                write(1, " ", 1);
        }
        while(str[i])
            free(str[i++]);
        free(str);
    }
    write(1, "\n", 1);
}