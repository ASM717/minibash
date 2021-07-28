#include "../minishell.h"

static void	ft_dollar_start(int *i, char **str, t_struct *env, int *flag)
{
	int	start;
	int	finish;

	start = 0;
	finish = 0;
	if (!(*flag) && (*str)[*i] == '\'')
		*flag = 1;
	else if ((*flag) && (*str)[*i] == '\'')
		*flag = 0;
	else if (!(*flag) && (*str)[*i] == '$' && !ft_isspace((*str)[(*i) + 1]))
	{
		if ((*str)[(*i) + 1] == '?')
			*str = ft_status_dollar(*str, *i, env);
		else
		{
			start = *i;
			finish = ft_check_finish(*str, start);
			*str = ft_dollar_change(*str, start, finish, env);
		}
		(*flag) = 0;
		*i = -1;
	}
}

char	*ft_check_dollar2(char *s, t_struct *env)
{
	int		i;
	int		flag;
	char	*str;

	i = 0;
	flag = 0;
	str = ft_strdup(s);
	free(s);
	while (str[i])
	{
		ft_dollar_start(&i, &str, env, &flag);
		i++;
	}
	return (str);
}
