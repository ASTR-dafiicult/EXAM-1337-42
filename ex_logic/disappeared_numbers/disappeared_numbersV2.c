# include <stdlib.h>
# include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}
void ft_putnbr(int nb)
{
    if(nb == 0)
        ft_putchar('0');
    if(nb > 9)
        ft_putnbr(nb / 10);
    ft_putchar((nb % 10) + 48);
}
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) 
{
    int i = 0;
    int index;
    while(i < numsSize)
    {
        index = abs(nums[i]) - 1;
        if(nums[index] > 0)
        {
            nums[index] = -nums[index];
        }
        i++;
    }
    int *res = malloc(numsSize * sizeof(int));
    if(!res)
        exit(EXIT_FAILURE);
    int index2 = 0;
    i = 0;
    while(i < numsSize)
    {
        if(nums[i] > 0)
            res[index2++] = i + 1;
        i++;
    }
    *returnSize = index2;
    return res;
}
int main()
{   
    //int arr[] = {1,1};
    int arr[] = {4,5,2,7,8,2,5,1};

    int count = 0;
    int *res = findDisappearedNumbers(arr, 8, &count);
    int i = 0;
    while(i < count)
    {
        ft_putnbr(res[i++]);
        if(i != count)
            ft_putchar(' ');
    }
    ft_putchar('\n');
    free(res);
}