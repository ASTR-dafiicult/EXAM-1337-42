# include <unistd.h>
# include <stdlib.h>

void	swap(char *c1, char *c2)
{
	char tmp = *c1;
	*c1 = *c2;
	*c2 = tmp;
}

void	ft_solve_helper(char *arry, int len , int index)
{
	int	i;

	if(index == len)
	{
		write(1, arry, len);
		write(1, "\n", 1);
		return;
	}
	i = index;
	while(i < len)
	{
		if(arry[index] != arry[i])
			swap((&arry[index]), (&arry[i])); 
	    
        ft_solve_helper(arry, len, index + 1);
		
        if(arry[index] != arry[i])
			swap((&arry[index]), &(arry[i]));
		i++;
	}
}

void	ft_permutation(char *str)
{
	int	i;
	char	*arry;

	i = 0;
	while (str[i])
		i++;
	arry = malloc((i + 1) * sizeof(char));
	if (!arry)
        	return ;
	arry[i] = '\0';
	while (*str)
	{
		*arry = *str;
		str++;
		arry++;
	}
	arry -= i;
	ft_solve_helper(arry, i, 0);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	ft_permutation(argv[1]);
}