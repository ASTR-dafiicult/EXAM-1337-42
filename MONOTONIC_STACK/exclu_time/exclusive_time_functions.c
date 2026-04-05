# include <stdlib.h>
# include <stdio.h>



int* exclusiveTime(int n, char** logs, int logsSize, int* returnSize)
{
    int     *stack = malloc(logsSize * sizeof(int));
    int     *res = calloc(n, sizeof(int));

    if(!res || !stack)
        exit(EXIT_FAILURE);

    int     j;
    int     id;
    int     time;
    char    type;
    int     i = 0;
    int     prev = 0;
    int     index = -1;

    while(i < logsSize)
    {
        id = 0;
        time = 0;
        j = 0;        
        while(logs[i] && logs[i][j] != ':')
        {
            id = id * 10 + (logs[i][j]) - 48;
            j++;
        }
        j++; //skip ':'
        type = logs[i][j];
        while(logs[i] && logs[i][j] != ':')
        {
            j++;
        }
        j++; //skip ':';
        while(logs[i][j])
        {
            time = time * 10 + (logs[i][j]) - 48;
            j++;
        }
        if(type == 's')
        {
            // stack[index++] = id;
            if(index != -1)
            {
                res[stack[index]] += time - prev;
            }
            stack[++index] = id;
            prev = time;
        }
        else
        {
            res[stack[index]] += time - prev + 1;
            index--;
            prev = time + 1;
        }
        i++;
    }
    *returnSize = n;
    free(stack);
    return res;
}
int main()
{
    char *logs[4];

    logs[0] = "0:start:0";
    logs[1] = "1:start:2";
    logs[2] = "1:end:5";
    logs[3] = "0:end:6";
    int n = 2;
    int cou = 0;
    int *res = exclusiveTime(n, logs, 4, &cou);

    int i = 0;
    while(i < cou)
        printf("%d ", res[i++]);
    printf("\n");
    free(res);
}