# include <stdio.h>

int solution(int number) 
{
    if(number < 0)
        return 0;
    int i = 2;
    int sum = 0;
    while(i < number)
    {
        if(i % 3 == 0 || i % 5 == 0)
        {
            sum += i;
        }
        i++;
    }
    return sum;
}
int main()
{
    int res = solution(1000);
    printf("%d\n", res);
}