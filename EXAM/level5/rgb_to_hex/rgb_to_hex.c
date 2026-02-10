# include <stdio.h>

void rgb(int r, int g, int b, char hex[]) 
{
    if(r > 255)
        r = 255;
    if(g > 255)
        g = 255;
    if(b > 255)
        b = 255;
    int rgb = (r << 16) | (g << 8) | b;
    sprintf(hex, "%06X", rgb);
}

int main() {
    int r = 148;
    int g = 0;      
    int b = 211;
    char hex[7];

    rgb(r, g, b, hex);
    printf("%s\n", hex);

    return 0;
}