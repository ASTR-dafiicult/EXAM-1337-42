# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>


int ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
        i++;
    return i;
}
//stope if is not self described
int stope(char *s, int len)
{
    int i = 0;
    int sum = 0;
    while(s[i])
        sum += s[i++] - 48;
    if(sum > len || sum < len)
        return 0;
    return 1;
}
//camp strings res genrate and funal result
int     ft_strcmp(char *s1, char *s2)
{
    int i = 0;
    while(s1[i] && s2[i])
    {
        if(s1[i] != s2[i])
            return 0;
        i++;
    }
    return 1;
} 
// checkchar from str is how many times on res
int     check1(char *res, char c_str)
{
    int i = 0;
    int count = 0;
    while(res[i])
    {
        if(res[i] == c_str)
            count++;
        i++;
    }
    return count;
}
// check validate full tab from check1 index
bool check_is_valid(char *res, char *str, int length)
{
    char *tab = malloc((length + 1) * sizeof(char));
    if(!tab)
        exit(EXIT_FAILURE);

    int i = 0;
    while(str[i])
    {
        int val = check1(res, str[i]);
        tab[i++] = val + 48;
    }
    tab[i] = '\0';
    if(ft_strcmp(tab, res))
    {
        free(tab);
        return true;
    }
    free(tab);
    return false;
}
//print identity
void ft_putstr(char *str)
{
    int i = 0;
    while(str[i])
        write(1, &str[i++], 1);
}
char *ft_identity1(char *str, char *res, int len)
{
    while(!check_is_valid(res ,str, len))
    {
        int i = 0;
        while(str[i])
        {
            int val = check1(res, str[i]);
            res[i++] = val + 48;
        }
        res[i] = '\0';
    }
    if(stope(res, len))
    {
        return res;
    }
    return NULL;
}
char *ft_identity2(char *str, char *res, int len)
{
    while(!check_is_valid(res, str, len))
    {
        char *tmp = malloc(len + 1);
        if(!tmp)
            exit(EXIT_FAILURE);
        int i = 0;
        while(str[i])
        {
            tmp[i++] = (check1(res, str[i]) + 48);
        }
        tmp[i] = '\0';
        i = 0;
        while(tmp[i])
        {
            res[i] = tmp[i];
            i++;
        }
        res[i] = '\0';
        free(tmp);
        ft_putstr(res);
    }
    if(stope(res, len))
    {
        return res;
    }
    return NULL;
}
void    ft_identity(char *str)
{
    int len = ft_strlen(str);
    if(len < 4 || len == 6)
        return;
    
    char *res = malloc(len + 1);
    if(!res)
        exit(EXIT_FAILURE);
    
    int i = 0;    
    while(i < len)
    {
        res[i++] = '0';
    }
    res[i] = '\0';
    if(len > 5 && len <= 10)
    {
        char *tab = ft_identity1(str, res, len);
        if(tab)
        {
            ft_putstr(tab);
            free(tab);
        }
        return;
    }
    if(len == 4)
    {
        int len_res = 2;
        while(len_res)
        {
            char *tab = ft_identity2(str, res, len);
            if(tab)
            {
                ft_putstr(tab);
            }
            i = 0;
            while(i < len)
            {
                res[i++] = '0';
                res[i++] = '1';
            }
            res[i] = '\0';
            len_res--;
            if(len_res != 0)
                write(1, "\n", 1);
        }
        free(res);
    }
    else if(len == 5)
    {
        char *tab = ft_identity2(str, res, len);
        if(tab)
        {
            ft_putstr(tab);
            free(res);
        }
    }
}
int main(int ac, char **av)
{
    if(ac == 2)
    {
        ft_identity(av[1]);
    }
    write(1, "\n", 1);
    return 0;
}