# include <unistd.h>

int check_char(char c, char *str)
{
    int i = 0;
    while(str[i])
    {
        if(str[i] == c)
        {
            return 1;
        }
        i++;
    }
    return 0;
}
void solve(char *s1, char *s2)
{
    int i = 0;
    int j = 0;
    char see[40] = {0};
    while(s1[i])
    {
        if(!check_char(s1[i], see))
        {
            see[j] = s1[i];
            j++;
        }
        i++;
    }
    i = 0;
    while(s2[i])
    {
        if(!check_char(s2[i], see))
        {
            see[j] = s2[i];
            j++;
        }
        i++;
    }
    i = 0;
    while(see[i])
    {
        write(1, &see[i], 1);
        i++;
    }
}
int main(int ac, char **av)
{
    if(ac == 3)
    {
        solve(av[1], av[2]);
    }
    write(1, "\n", 1);
}