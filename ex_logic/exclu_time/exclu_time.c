# include <unistd.h>
# include <stdlib.h>


void ft_putchar(char c)
{
    write(1, &c, 1);
}
void ft_putnbr(int nb)
{
    if(nb < 0)
    {
        ft_putchar('-');
        nb = -nb;
    }
    if(nb > 9)
        ft_putnbr(nb / 10);
    ft_putchar(nb % 10 + 48);
}
void get_data(char *log, int *time, int *id, char *type)
{
    int i = 0;
    while(log[i] != ':')
    {
        *id = *id * 10 + log[i] - 48;
        i++;
    }
    i++; // skip ':'
    *type = log[i];
    while(log[i] != ':')
    {
        i++;
    }
    i++;//skip ':'
    while(log[i])
    {
        *time = *time * 10 + log[i] - 48;
        i++;
    }
}
int* exclusiveTime(int n, char** logs, int logsSize, int* returnSize)
{
    int *stack = malloc(logsSize * sizeof(int));
    int *result = calloc(n, sizeof(int));
    if(!stack || !result)
        exit(EXIT_FAILURE);

    int index = -1;
    int i = 0;
    char type;
    int prev;
    int time;
    int id;
    while(i < logsSize)
    {
        time = 0;
        id = 0;
        get_data(logs[i], &time, &id, &type);
        if(type == 's')
        {
            if(index != -1)
            {
                result[stack[index]] += time - prev;
            }
            stack[++index] = id;
            prev = time;
        }
        else
        {
            result[stack[index--]] += (time - prev) + 1;
            prev = time + 1;
        }
        i++;
    }
    *returnSize = n;
    free(stack);
    return result;
}
int main()
{
    char *logs[4];

    logs[0] = "0:start:0";
    logs[1] = "1:start:2";
    logs[2] = "1:end:5";
    logs[3] = "0:end:6";

    int n = 2;
    int size = 0;
    int *res = exclusiveTime(n, logs, 4, &size);
    int i = 0;

    while(i < size)
    {
        ft_putnbr(res[i++]);
        if(i != size)
            ft_putchar(' ');
    }
    ft_putchar('\n');
    free(res);

}