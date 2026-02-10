# include <stdio.h>



unsigned char	reverse_bits(unsigned char octet)
{
    int i = 0;
    unsigned char res = 0;
    while(i < 8)
    {
        res = (res << 1) | (octet & 1);// (0000 0000) == res | octet & 1 (last bist and 1)
        // == 1 res = 0000 0001...... every time when res = 1 add 1 to res
        octet = octet >> 1; // shift octet into right 
        i++;
    }
    return res;
}
int main()
{
    unsigned char octet = 38;
    printf("%d\n", reverse_bits(octet));
}