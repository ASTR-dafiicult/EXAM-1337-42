# include <unistd.h>
# include <stdio.h>



size_t	ft_strcspn(const char *s, const char *reject)
{
    size_t len = 0;
    while(s[len])
        len++;

    size_t i = 0;
    size_t j;
    while(s[i])
    {
        j = 0;
        while(reject[j])
        {
            if(s[i] == reject[j])
            {
                return i;
            }
            j++;
        }
        i++;
    }
    return len;
}
int main()
{
    char *str = "hello";
    char *reject = "koma";
    printf("%ld\n", ft_strcspn(str, reject));
}