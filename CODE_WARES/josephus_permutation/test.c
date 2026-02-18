# include <unistd.h>
# include <stdio.h>

int who_dead(int index, int nb, int k)
{
    if(index >= 0 && index <= 9)
    {
        index = (index + k - 1) % nb;
        return index;
    }
    return -1;
}
void joesephus_permutation(int n, int array[n], int tab[n], int k)
{
    int i = 0;
    int j = 0;
    int index = 0;
    int nbr= n;
    while(n)
    {
        index = who_dead(index, n, k);
        if(index != -1)
        {
            array[j++] = tab[index];
        } 
        i = index;
        while(i < n - 1)
        {
            tab[i] = tab[i + 1];
            i++;
        }
        n--;
        if(index == n)
            index = 0;
    }
    i = 0;
    while(i < nbr)
    {
        printf("%d ", array[i++]);
    }
    printf("\n");
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int array[7];
    joesephus_permutation(5, array, arr, 3);
}