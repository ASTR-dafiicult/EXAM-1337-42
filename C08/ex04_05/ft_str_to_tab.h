# ifndef FT_STRS_TO_TAB
# define FT_STRS_TO_TAB

typedef struct s_stock_str
{
    int size;
    char *str;
    char *copy;
}                   t_stock_str;
struct s_stock_str *ft_strs_to_tab(int ac, char **av);
void ft_show_tab(struct s_stock_str *par);
#endif