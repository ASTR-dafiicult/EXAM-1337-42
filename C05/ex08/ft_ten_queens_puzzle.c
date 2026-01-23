# include "unistd.h"
# include "stdio.h"



void ft_putchar(char c)
{
    write(1, &c, 1);
}
int check_place(int queens[10], int row, int col)
{
    int i = 0;
    while(i < col)
    {
        if(queens[i] == row)
        {
            return 0;
        }
        if(queens[i] + i == row + col)
        {
            return 0;
        }
        if(queens[i] - i == row - col)
        {
            return 0;
        }
        i++;
    }
    return 1;
}
void print_queens(int queens[10])
{
    int i = 0;
    while(i < 10)
    {
        ft_putchar(queens[i] + 48);
        i++;
    }
    write(1, "\n", 1);
}
int place_queens(int queens[10], int col, int *index)
{
    if(col == 10)
    {
        print_queens(queens);
        (*index)++;
    }
    int row = 0;
    while(row < 10)
    {
        if(check_place(queens, row, col))
        {
            queens[col] = row;
            place_queens(queens, col + 1, index);
        }
        row++;
    }
    return *index;
}
int ft_ten_queens_puzzle(void)
{
    int queens[10];
    int index = 0;
    return place_queens(queens, 0, &index);
}
int main()
{
    printf("number of solutions are : %d\n", ft_ten_queens_puzzle());
}