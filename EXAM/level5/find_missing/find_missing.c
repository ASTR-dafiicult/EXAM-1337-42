# include <unistd.h>
# include <stdio.h>


char check_char(char c)
{
   return (c += 1);
}
char findMissingLetter(char array[], int arrayLength)
{
    int i = 0;
    char c;
    int j = 1;
    char missing;
    while(array[i] && i < arrayLength - 1)
    {
        missing = check_char(array[i]);
        if(missing != array[j + i])
            return missing;
        i++;
    }
    return ' ';
}
int main()
{
    char arr[] = {'a', 'b', 'c', 'd', 'e'};
    printf("%c\n", findMissingLetter(arr, 5));
}