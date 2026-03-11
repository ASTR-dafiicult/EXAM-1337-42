# include <unistd.h>

int ft_atoi(char *str)
{
    int i = 0;
    int res = 0;
    while(str[i] == 32 || str[i] == 9)
        i++;
    while(str[i])
    {
        res = res * 10 + str[i++] - 48;
    }
    return res;
}
void ft_putchar(char c)
{
    write(1, &c, 1);
}
void ft_putnbr(int nb)
{
    if(nb == 0)
    {
        ft_putchar('0');
        return;
    }
    if(nb > 9)
        ft_putnbr(nb / 10);
    ft_putchar((nb % 10) + 48);
}
int isSafe(int n ,int Q[n], int row, int col)
{
    int i = 0;
    while(i < row)
    {
        if(Q[i] == col)
            return 0;
        if(Q[i] + i == row + col)
            return 0;
        if(Q[i] - i == col - row)
            return 0;

        i++;
    }
    return 1;
}
void print_solution(int n, int Q[n])
{
    int i = 0;
    while(i < n)
    {
        ft_putnbr(Q[i++]);
    }
    printf("\n");
}
int solve_n_queen(int n, int Q[n], int row, int *counter)
{
    if(n == row)
    {
        print_solution(n, Q);
        (*counter)++;
    }
    int col = 0;
    while(col < n)
    {
        if(isSafe(n, Q, row, col))
        {
            Q[row] = col;
            solve_n_queen(n , Q, row + 1, counter);
        }
        col++;
    }
    return *counter;
}
void N_queens_problem(int n)
{
    int row = 0;
    int Q[n];
    int count = 0;
    count = solve_n_queen(n, Q, row, &count);
    ft_putnbr(count);
}
int main(int ac, char **av)
{
    if(ac == 2)
    {
        int nb = ft_atoi(av[1]);
        if(nb <= 0)
        {
            ft_putnbr(0);
            ft_putchar('\n');
            return 0;
        }
        N_queens_problem(nb);
    }
    ft_putchar('\n');
}
