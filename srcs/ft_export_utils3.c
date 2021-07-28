#include "../minishell.h"

char	*ft_change_value(char	*str, t_list *tmp)
{
	free(tmp->content);
	return (ft_strdup(str));
}

int	ft_search_elem(t_struct *env, char *str)
{
	t_list	*tmp;
	char	**s;

	tmp = env->s_env;
	s = ft_split(str, '=');
	while (tmp)
	{
		if (!ft_strncmp(s[0], tmp->content, ft_strlen(s[0])))
		{
			if (s[1])
				tmp->content = ft_change_value(str, tmp);
			ft_free(s);
			return (1);
		}
		tmp = tmp->next;
	}
	ft_free(s);
	return (0);
}
