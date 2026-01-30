# include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}
void print_val(int nb)
{
    if(nb == 0)
        ft_putchar('0');
        return;
    if(nb > 9)
        print_val(nb / 10);
    ft_putchar(nb % 10 + 48);
}
void sort_int_tab(int *tab, unsigned int size)
{
    unsigned int i;
    unsigned int j;
    
    i = 0;
    while(i < size)
    {
        j = i + 1;
        while(j < size)
        {
            if(tab[i] > tab[j])
            {
                int tmp = tab[j];
                tab[j] = tab[i];
                tab[i] = tmp;
            }
            j++;
        }
        i++;
    }
    i = 0;
    while(i < size)
    {
        print_val(tab[i++]);
        if(i != size)
            ft_putchar(' ');
    }
}
int main()
{
    int tab[] = {12, 4, 6, 6, 8, 1, 13, 90, 1};
    unsigned int size = 9;
    sort_int_tab(tab, size);
    ft_putchar('\n');
}