#include "../minishell.h"

void	ft_norm_check_pipe(int i, int *flag, char *str, char c)
{
	if (i < ft_strlen(str) && str[i] == c)
		(*flag)++;
	if (*flag > 1)
		printf("minishell: syntax error near unexpected token `%c'\n", c);
	if (*flag == 1)
		printf("minishell: syntax error near unexpected token `newline'\n");
}

int	ft_check_norm_red(int i, int *flag, char *str, char c)
{
	if (i < ft_strlen(str) && str[i] == c)
		(*flag)++;
	if (*flag > 2)
	{
		if (*flag > 3)
		{
			printf("minishell: syntax error near unexpected token `%c%c'\n",
				c, c);
			return (1);
		}
		printf("minishell: syntax error near unexpected token `%c'\n", c);
		return (1);
	}
	if (*flag)
		printf("minishell: syntax error near unexpected token `newline'\n");
	return (0);
}
