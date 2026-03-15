# include <unistd.h>
# include <stdio.h>


int ft_border_sum(int **matrix, int rows, int cols)
{
    int i = 0;
    int j = 0;
    int sum = 0;
    while(i < rows)
    {
        j = 0;
        while(j < cols)
        {
            if(i == 0 || (i > 0 && i + j == i))
            {   
                sum += matrix[i][j];
            }
            else if(i == rows - 1 || j == cols - 1)
            {
                sum += matrix[i][j];
            }
            j++;
        }
        i++;
    }
    return sum;
}
# include <stdlib.h>
int main()
{
    int rows = 4;
    int cols = 4;
    int data[4][4] = {
        {1, 1, 1, 1},
        {1, 2, 2, 1},
        {1, 2, 2, 1},
        {1, 1, 1, 1},
    };

    int *matrix[4];
    int i = 0;
    while(i < rows)
    {
        matrix[i] = data[i];
        i++; 
    }
    int sum = ft_border_sum(matrix, rows, cols);
    printf("%d\n", sum);
}
//**matrix
// ↓
//[p][p][p][p]
// ↓ ↓ ↓ ↓
//row row row row