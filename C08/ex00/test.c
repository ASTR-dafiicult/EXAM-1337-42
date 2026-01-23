# include "ft.h"

int main()
{
    //ft_strlen
    char *str = "hello boys";
    printf("strlen : %d\n", ft_strlen(str));
    
    //ft_strcmp
    char *s1 = "hello";
    char *s2 = "hallo";
    printf("strcmp : %d\n", ft_strcmp(s1, s2));
    
    //ft_swap
    int a = 10;
    int b = 20;
    ft_swap(&a, &b);
    printf("swap : a = %d | b = %d\n", a, b);

    // ft_putstr
    char *src = "hello this is me\n";
    ft_putstr(src);
}