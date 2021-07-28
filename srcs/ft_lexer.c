#include "../minishell.h"

int	ft_check_pipe(char *str, char c)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	if (str[0] == c)
		flag++;
	while (i < ft_strlen(str) - 1)
	{
		while (str[i] && str[i++] == c)
			flag++;
		if (flag && str[i] != c)
		{
			if (flag > 2)
				break ;
			flag = 0;
		}
		i++;
	}
	ft_norm_check_pipe(i, &flag, str, c);
	return (flag);
}

int	ft_check_quotes(char *str, char c)
{
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	if (ft_check_space(str, c) || ft_check_space(str, c))
		return (1);
	while (str[i])
	{
		if (!flag && str[i] == c)
			flag = 1;
		else if (flag && str[i] == c)
			flag = 0;
		i++;
	}
	if (flag)
	{
		printf("minishell: %s: No such file or directory\n", str);
		return (1);
	}
	return (0);
}

int	ft_check_redirect(char *str, char c)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	if (str[0] == c)
		flag++;
	while (i < ft_strlen(str) - 1)
	{
		while (str[i] && str[i++] == c)
			flag++;
		if (flag && str[i] != c)
		{
			if (flag > 2)
				break ;
			flag = 0;
		}
		i++;
	}
	ft_check_norm_red(i, &flag, str, c);
	return (flag);
}

int	ft_check_symbol(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_lexer(t_struct *env)
{
	if (ft_check_pipe(env->s_cmd_line, '|'))
		return (258);
	if (ft_check_quotes(env->s_cmd_line, '\'')
		|| ft_check_quotes(env->s_cmd_line, '\"'))
		return (127);
	if (ft_check_redirect(env->s_cmd_line, '>')
		|| ft_check_redirect(env->s_cmd_line, '<'))
		return (258);
	return (0);
}
