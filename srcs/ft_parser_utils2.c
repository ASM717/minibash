#include "../minishell.h"

void	ft_pass_quote(int *i, char *str)
{
	if (str[*i] && str[*i] == '\'')
	{
		(*i)++;
		while (str[*i] && str[*i] != '\'')
			(*i)++;
	}
	if (str[*i] && str[*i] == '\"')
	{
		(*i)++;
		while (str[*i] && str[*i] != '\"')
			(*i)++;
	}
}

int	ft_find_redirection(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		ft_pass_quote(&i, str);
		flag++;
		if (ft_strncmp(&str[i], ">>", 2) == 0)
			return (i);
		else if (ft_strncmp(&str[i], ">", 1) == 0)
			return (i);
		else if (ft_strncmp(&str[i], "<<", 2) == 0)
			return (i);
		else if (ft_strncmp(&str[i], "<", 1) == 0)
			return (i);
		else
			flag--;
		i++;
	}
	if (flag)
		return (0);
	return (-1);
}

void	ft_redirect_check_out(t_list1 *tmp)
{
	int		i;
	char	*str;

	str = 0;
	i = 0;
	if (tmp->command)
		i = ft_find_redirection(tmp->command);
	if (i > 0)
	{
		str = ft_strdup(tmp->command);
		free(tmp->command);
		tmp->command = 0;
		tmp->command = ft_substr(str, 0, i);
		tmp->redcom = ft_strdup(&str[i]);
		free(str);
	}
	else if (i == 0)
	{
		tmp->redcom = ft_strdup(tmp->command);
		free(tmp->command);
		tmp->command = 0;
	}
}

int	ft_is_redirect(char *s)
{
	if (ft_strncmp(s, ">>", 2) == 0)
		return (2);
	else if (ft_strncmp(s, ">", 1) == 0)
		return (1);
	else if (ft_strncmp(s, "<<", 2) == 0)
		return (2);
	else if (ft_strncmp(s, "<", 1) == 0)
		return (1);
	return (0);
}

int	ft_check_end(char *str, int i)
{
	i++;
	while (str[i] && ft_is_redirect(&str[i]) == 0)
		i++;
	return (i);
}
