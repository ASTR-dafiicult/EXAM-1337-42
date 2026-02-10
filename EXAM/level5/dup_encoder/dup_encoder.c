# include <stdlib.h>

void ft_putstr(char *str)
{
  int i = 0;
  while(str[i])
    write(1, &str[i++], 1);
}
int frequence(char *str, char c)
{
  int i = 0;
  int counter = 0;
  char c1;
  char c2;
  while(str[i])
  {
    c1 = str[i];
    c2 = c;
    if(c1 >= 'A' && c1 <= 'Z')
      c1 += 32;
    if(c2 >= 'A' && c2 <= 'Z')
      c2 += 32;
    if(c1 == c2)
      counter++;

    i++;
  }
  return counter;
}
char *DuplicateEncoder (const char *string)
{
    int i;
    int j = 0;
    int len = 0;

    while(string[len])
    len++;
    
    char *dup = malloc(len + 1);
    char *dup2 = malloc(len + 1);
    if(!dup || !dup2)
        exit(EXIT_FAILURE);
  
    while(string[j])
    {
        dup[j] = string[j];
        dup2[j] = string[j];
        j++;
    }
    dup[j] = '\0';
    
    i = 0;
    j = 0;
    int freq = 0;
    while(dup[i])
    {
        freq = frequence(dup2, dup[i]);
        if(freq > 1)
        {
          dup[i] = ')';
        }
        else
        {
          dup[i] = '(';
        }
        i++;
    }
    dup[i] = '\0';
    return dup;
}
/*
# include <stdio.h>
int main(int ac, char **av)
{
  if(ac != 2)
  {
    write(1, "\n", 1);
    exit(EXIT_FAILURE);
  }
  else
  {
    char *str = DuplicateEncoder(av[1]);
    ft_putstr(str);
    free(str);
  }
  write(1, "\n", 1);
  exit(EXIT_SUCCESS);
}
*/