# include <stdlib.h>
# include <stdio.h>


int caesar_cipher(char c)
{
    if((c >= 'A' && c <= 'M') || (c >= 'a' && c <= 'm'))
        return c += 13;
    else if((c >= 'N' && c <= 'Z') || (c >= 'n' && c <= 'z'))
        return c -= 13;
    return 48;
}
char *rot13(const char *src)
{
    int len = 0;
    while(src[len])
        len++;
    char *str = calloc(len + 1, sizeof(char));
    if(!str)
        exit(EXIT_FAILURE);
    int i = 0;
    char  val;
    while(src[i])
    {
        val = caesar_cipher(src[i]);
        if(val != 48)
            str[i] = val;
        else
            str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return str;
}
int main()
{
    const char *str = "AkjhZ zLKIJz , 23y ";
    char *res = rot13(str);
    printf("%s\n", res);
}