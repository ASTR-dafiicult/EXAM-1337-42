# include <stdio.h>
# include "lib.h"

pair solution(unsigned first, unsigned second) 
{
    pair res;
    int next = 0;
    int f = first;
    int s = second;
    while(s - f <= f)   
    {   
        next = s - f;
        s = f;
        f = next;
    }
    res.first = f;
    res.second = s;
    return res;
}
int main()
{
    pair res = solution(398, 644);
    printf("%d %d\n", res.first, res.second);
}