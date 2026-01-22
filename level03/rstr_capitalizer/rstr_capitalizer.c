# include <unistd.h>

void ft_pucthar(char c)
{
    write(1, &c, 1);
}
void rstr_capitalizer(char *str)
{
    int i = 0;
    while(str[i])
    {
        if(str[i + 1] == 32 || str[i + 1] == 9 || str[i + 1] == '\0')
        {
            if(str[i] >= 'a' && str[i] <= 'z')
            {
                ft_pucthar(str[i] - 32);
            }
            else
                ft_pucthar(str[i]);
        }
        else if((str[i] >= 'a' && str[i] <= 'z') && (str[i + 1] != 32 || str[i + 1] != 9 || str[i + 1] != '\0'))
        {
            ft_pucthar(str[i]);
        }
        else if((str[i] >= 'A' && str[i] <= 'Z') && (str[i + 1] != 32 || str[i + 1] != 9 || str[i + 1] != '\0'))
        {
            ft_pucthar(str[i] + 32);
        }
        else{
            ft_pucthar(str[i]);
        }
        i++;
    }
}
int main(int ac, char **av)
{
    if(ac > 1)
    {
        int i = 1;
        while(av[i] && i < ac)
        {
            rstr_capitalizer(av[i]);
            ft_pucthar('\n');
            i++;
        }
    }
    write(1, "\n", 1);
}
