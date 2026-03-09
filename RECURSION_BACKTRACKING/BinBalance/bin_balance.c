# include <unistd.h>
# include <stdlib.h>



void print_possibles(char *str, int sum1, int sum2)
{
    if(sum1 == sum2)
    {
        int i = 0;
        while(str[i])
        {
            write(1, &str[i++], 1);
        }
        write(1, "\n", 1);
    }
    else
        return;
}
void ft_possibles(char *str, int sum1, int sum2, int index, int len)
{
    // thriiib lmokhdirat (:~ >|
    int n = str[len + 1];

    if(index == n*2)           
    {
        str[index] = '\0';
        print_possibles(str, sum1, sum2);
        return;                                 
    }
    str[index] = '0';

    if(index < n)
        ft_possibles(str, sum1, sum2, index + 1, len); // 0 0 0 1
    else
        ft_possibles(str, sum1, sum2, index + 1, len);

    str[index] = '1';
    if(index < n)
        ft_possibles(str, sum1 + 1, sum2, index + 1, len);
    else
        ft_possibles(str, sum1, sum2 + 1, index + 1, len);
}
int main()
{
    int n = 2;
    int len = (n * 2 + 1);
    char *str = calloc((len), sizeof(char));
    if(!str)
        exit(EXIT_FAILURE);
    str[len + 1] = n;
    ft_possibles(str, 0, 0, 0, len);
    free(str);
}