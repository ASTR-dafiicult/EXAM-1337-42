# include <unistd.h>
# include <stdlib.h>

typedef long long Fraction[2]; // { numerator, denominator }
long gcd(long a1, long b1)
{
    int rem = 0;
    int total = 0;
    while(b1 != 0)
    {
        total = a1 % b1;
        a1 = b1;
        b1 = total;
    }
    return a1;
}
long lcm(long a, long b)
{
    long a1 = a, b1 = b;
    int rem;
    while((rem = a % b) != 0)
    {
        a = b;
        b = rem;
    }
    return (a1 * b1) / gcd(a1, b1);
}
Fraction *convertFrac(const Fraction fractions[/*n*/], unsigned n)
{
    Fraction *arr = malloc(sizeof(Fraction) * n);
    //Array of Fraction = n rows × 2 columns → behaves like 2D array
    if(!arr)
        exit(EXIT_FAILURE); 
        unsigned i = 0;
        while(i < n)
    {
        arr[i][0] = fractions[i][0];
        arr[i][1] = fractions[i][1];
        i++;
    }
    i = 0;
    while(i < n)
    {
        long num_gcd = gcd(fractions[i][0], fractions[i][1]);
        arr[i][0] /= num_gcd;
        arr[i][1] /= num_gcd;
        i++;
    }
    i = 0;
    long val = arr[0][1]; // first  dinominator
    while(i < n)
    {
        val = lcm(val, arr[i++][1]);
    }
    i = 0;
    while(i < n)
    {
        arr[i][0] = arr[i][0] * (val / arr[i][1]);
        arr[i][1] = val;
        i++;
    }
    return arr;
    
}
/**/
# include <stdio.h>
int main()
{
    const Fraction array[] = { {1, 2}, {1 ,3}, {1, 4} };
    unsigned n = 3;
    Fraction *arr = convertFrac(array, n);
    unsigned i = 0;
    unsigned j;
    while(i < n)
    {
        j = 0;
        while(j < n - 1)
        {
            if(j == 0)
                printf("( ");
            printf("%lld ", arr[i][j++]);
        }
        printf(")");
        i++;
    }
    i = 0;
    free(arr);
    printf("\n");
}