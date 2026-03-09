# include <unistd.h>

void swap(char *c1, char *c2)
{
    char tmp = *c1;
    *c1 = *c2;
    *c2 = tmp;
}
void ft_permutation(char *str, int len , int index)
{
    if(index == len)
    {
        write(1, str, len);
        write(1, "\n", 1);
        return;
    }
    int i = index;
    while(i < len)
    {
        if(str[index] != str[i]) //choice
            swap((&str[index]), (&str[i]));

        ft_permutation(str, len, index + 1);//recursion

        if(str[index] != str[i])//backtracking
            swap((&str[index]), &(str[i]));
        i++;
    }
}
# include <stdlib.h>
int main()
{
    int len = 3;
    char *str = malloc((len + 1) * sizeof(char));
    if(!str)
        exit(EXIT_FAILURE);

    int a = 97;
    int i = 0;
    while(i < len)
    {
        str[i++] = a++;
    }
    str[i] = '\0';

    ft_permutation(str, len, 0);
}
