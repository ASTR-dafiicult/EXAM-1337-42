# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>



int check_prime(int nb)
{
    int i = 2;
    while(i < nb / 2)
    {
        if(nb % i == 0)
            return 0;
        i++;
    }
    return 1;
}
char *sumOfDivided(const int numbers[/*count*/], int count)
{
    char *tab = malloc((count + 1) * sizeof(char));
    if(!tab)
        return NULL;

    int i = 2;
    int j = 0;
    while(i < count)
    {
        if(i % numbers[i] == 0)
        {
            tab[j++] = i + '0';
        }
        i++;
    }
    tab[j] = '\0';
    return tab;

    // return a heap-allocated string
	//return calloc(1, 1);
}
int main()
{
    const int arr[] = {12, 5};
    char *str = sumOfDivided(arr, 2);
    printf("%s\n", str);
}