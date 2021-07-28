#include "../minishell.h"

char	*ft_getenv(t_struct *env)
{
	t_list	*tmp;

	tmp = env->s_env;
	while (tmp)
	{
		if (!ft_strncmp(tmp->content, "PATH=", 5))
			return (ft_substr(tmp->content, 5, ft_strlen(tmp->content)));
		tmp = tmp->next;
	}
	return (NULL);
}

int	ft_check_space(char *str, char c)
{
	char	**tmp;

	tmp = 0;
	tmp = ft_split(str, c);
	if (!tmp || !ft_check_line(tmp[0]))
	{
		if (tmp)
			printf("minishell: %s: No such file or directory\n", tmp[0]);
		else
			printf("minishell: : command not found\n");
		if (tmp)
			ft_free(tmp);
		return (1);
	}
	if (tmp)
		ft_free(tmp);
	return (0);
}
