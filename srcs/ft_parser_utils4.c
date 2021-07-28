#include "../minishell.h"

static char	*ft_split_command(char *str, char c)
{
	char	**s;
	char	*stroka;
	int		i;

	s = ft_split(str, c);
	if (!ft_check_line(s[0]))
	{
		free(str);
		str = ft_strdup(s[0]);
		free(str);
		return (s[0]);
	}
	free(str);
	stroka = ft_strdup(s[0]);
	str = ft_space(stroka);
	free(stroka);
	i = 1;
	while (s[i])
	{
		stroka = ft_space(s[i++]);
		str = ft_strjoin1(str, stroka);
		free(stroka);
	}
	ft_free(s);
	return (str);
}

char	*ft_name_check1(char *str)
{
	if (!ft_strchr(str, '\"'))
		return (str);
	if (ft_strchr(str, '\"'))
		return (ft_split_command(str, '\"'));
	return (str);
}

char	*ft_name_check2(char *str)
{
	if (!ft_strchr(str, '\''))
		return (str);
	else if (ft_strchr(str, '\''))
		return (ft_split_command(str, '\''));
	return (str);
}

void	ft_name_quotes1(t_list1 *tmp)
{
	int	i;

	i = 0;
	while (tmp->temporary[i])
	{
		tmp->temporary[i] = ft_name_check1(tmp->temporary[i]);
		i++;
	}
}

void	ft_name_quotes2(t_list1 *tmp)
{
	int	i;

	i = 0;
	while (tmp->temporary[i])
	{
		tmp->temporary[i] = ft_name_check2(tmp->temporary[i]);
		i++;
	}
}
