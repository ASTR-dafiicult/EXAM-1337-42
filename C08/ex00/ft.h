# include "unistd.h"
# include "stdio.h"



void ft_putchar(char c)
{
    write(1, &c, 1);
}
void ft_swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void ft_putstr(char *str)
{
    int i = 0;
    while(str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
}
int ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
    {
        i++;
    }
    return i;
}
int ft_strcmp(char *s1, char *s2)
{
    int i = 0;
    while(s1[i] || s2[i])
    {
        if(s1[i] != s2[i])
        {
            return s1[i] - s2[i];
        }
        i++;
    }
    return s1[i] - s2[i];
}