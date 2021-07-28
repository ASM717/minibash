#include "../minishell.h"

char	*ft_check_env_param(char *str, t_struct *env)
{
	t_list	*tmp;
	char	**s;
	char	*stroka;

	tmp = env->s_env;
	stroka = 0;
	while (tmp)
	{
		s = ft_split(tmp->content, '=');
		if (s[1] && !ft_strncmp(str, s[0], ft_strlen(s[0]))
			&& ((ft_strlen(str) == ft_strlen(s[0])
					|| ft_isspace(str[ft_strlen(s[0]) + 1]))))
		{
			free(str);
			stroka = ft_strdup(s[1]);
			ft_free(s);
			return (stroka);
		}
		ft_free(s);
		tmp = tmp->next;
	}
	free(str);
	return (0);
}

char	*ft_dollar_change(char *str, int start, int finish, t_struct *env)
{
	char	*tmp;
	char	*stroka;
	char	*s;

	tmp = ft_check_env_param(ft_substr(&str[1], start, finish), env);
	s = ft_substr(str, 0, start);
	s = ft_strjoin1(s, tmp);
	stroka = ft_substr(str, finish, ft_strlen(str));
	s = ft_strjoin1(s, stroka);
	free(stroka);
	free(tmp);
	if (str)
	{
		free(str);
		str = NULL;
	}
	return (s);
}

int	ft_check_finish(char *str, int start)
{
	char	c;
	int		i;

	c = str[start];
	i = start;
	while (str[i] && i < ft_strlen(str))
	{
		if (c == '$')
		{
			start++;
			while (str[start] && ft_isspace(str[start]) == 0
				&& str[start] != '$')
				start++;
			return (start);
		}
		i++;
	}
	return (0);
}

char	*ft_status_dollar(char *str, int i, t_struct *env)
{
	char	*s;
	char	*tmp;

	s = ft_substr(str, 0, i);
	tmp = ft_itoa(env->status);
	s = ft_strjoin1(s, tmp);
	free(tmp);
	if (str[i + 2])
		s = ft_strjoin1(s, ft_substr(str, i + 2, ft_strlen(str)));
	free(str);
	return (s);
}

void	ft_check_dollar(t_list1 *tmp, t_struct *env)
{
	int	i;

	i = 0;
	while (tmp->temporary[i])
	{
		if (ft_strchr(tmp->temporary[i], '$'))
			tmp->temporary[i] = ft_check_dollar2(tmp->temporary[i], env);
		i++;
	}
}
