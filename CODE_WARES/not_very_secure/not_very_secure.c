# include <stdio.h>
#include <stdbool.h>

bool check_string(char c)
{
    if(!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')))
        return false;
    return true;
}
bool find_char(char c)
{
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return true;
    return false;
}
bool alphanumeric(const char *str_in)
{
    int i = 0;
    while(str_in[i])
    {
        if(!check_string(str_in[i]))
            return false;
        i++;
    }
    i = 0;
    int found = 0;
    while(str_in[i])
    {
        if(find_char(str_in[i]))
            found++;
        i++;
    }
    if(found == 0)
        return false;
    return true;
}
int main()
{
    const char *str = "28";
    bool res = alphanumeric(str);
    if(res)
        printf("is alpha\n");
    else
        printf("not alpha\n");
}