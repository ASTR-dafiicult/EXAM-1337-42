# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int check_char(char c)
{
    int i = 0;
    char *base = "01";
    while(base[i])
    {
        if(base[i] == c)
            return i;
        i++;
    }
    return -1;
}
unsigned long long conver(char *str)
{
    int i = 0;
    unsigned long long res = 0;
    while(str[i])
    {
        int val = check_char(str[i]);
        if(val != -1)
        {
            res = res * 2 + val;
        }
        else
            return 0;
        i++;
    }
    return res;
}
char* addBinary(char* a, char* b)
{
    if((a[0] == '0' && a[1] == '\0') && (b[0] == '0' && b[1] == '\0'))
    {
        char *str = malloc(2);
        str[0] = '0';
        str[1] = '\0';
        return str;
    }
    unsigned long long nb_a = conver(a);
    unsigned long long nb_b = conver(b);
    if(!(nb_a || nb_b))
        exit(EXIT_FAILURE);

    unsigned long long sum = nb_a + nb_b;
    unsigned long long tmp = sum;
    int size = 0;
    while(tmp)
    {
        tmp /= 2;
        size++;
    }
    char *sum2 = calloc((size + 1), sizeof(char));
    if(!sum2)
        exit(EXIT_FAILURE);
    
    sum2[size] = '\0';    
    int i = size - 1;
    int j = 0;
    while(i >= 0)
    {
        sum2[i--] = sum % 2 + 48;
        sum /= 2;
    }
    return sum2;
}
int main()
{
    char *a = "11";
    char *b = "1";
    printf("%s\n", addBinary(a, b));
}