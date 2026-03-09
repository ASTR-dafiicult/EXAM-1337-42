# include <unistd.h>
# include <stdlib.h>

int check_char(char c, char *str, int index)
{
    int i = index;
    while(str[i])
    {
    	if(str[i] == c)
		return 1;
	i++;
    }
    return 0;
}
int maxlenoc(int index, int ac, char **av, char c)
{
	int i = 2;
	while(i < ac)
	{
		if(check_char(c, av[i], index) != 1)
		{
			return 0;
		}
		i++;
	}
	return 1;
}
int main(int ac, char **av)
{
	if(ac >= 2)
	{
		int len = 0;
		while(av[1][len]) len++;
		char *str = malloc((len + 1) * sizeof(char));
		if(!str)
			exit(EXIT_FAILURE);
		str[0] = '\0';
		int i = 0;
		int j = 0;
		int index = 0;
		while(av[1][i])
		{
			if(maxlenoc(index, ac, av, av[1][i]))
			{
				int k = 0;
				if(!check_char(av[1][i], str, k))
					str[j++] = av[1][i];
				index++;	
			}
			i++;
		}
		str[j] = '\0';
		i = 0;
		while(str[i])
			write(1, &str[i++], 1);
		free(str);
	}
	write(1, "\n", 1);
	return 0;
}