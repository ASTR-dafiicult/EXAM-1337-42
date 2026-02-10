# include <stdlib.h>
# include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}
void print_number(int nb)
{    
    if(nb > 9)
        print_number(nb / 10);
    ft_putchar((nb % 10) + 48);
}
int check_type(int num)
{
    if(num % 2 != 0)
        return 1;
    else
        return 0;
}
void sort_array(size_t n, int arr[n])
{
    if(n == 0)
        exit(EXIT_FAILURE);
    size_t i = 0;
    size_t j;
    int tmp;
    while(i < n)
    {
        j = i + 1;
        while(j < n - 1)
        {
            if(check_type(arr[i]) && check_type(arr[j]))
            {
                if(arr[i] > arr[j])
                {
                    tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                }
            }
            j++;
        }
        i++;
    }
    i = 0;
    while(i < n)
    {
        print_number(arr[i++]);
        if(i != n)
            ft_putchar(' ');
    }
    ft_putchar('\n');
    exit(EXIT_SUCCESS);
}
int main()
{
    int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    sort_array(10, arr);
}