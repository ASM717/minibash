#include "../minishell.h"

static void	ft_swap_list(char **s1, char **s2)
{
	char	*tmp;

	tmp = ft_strdup(*s1);
	free(*s1);
	*s1 = ft_strdup(*s2);
	free(*s2);
	*s2 = ft_strdup(tmp);
	free(tmp);
}

static char	*ft_str_export(char	*str)
{
	char	*s;
	int		i;
	int		j;
	int		len;

	len = ft_strlen(str) + 3;
	s = (char *)malloc(sizeof(char) * len);
	len = 0;
	i = 0;
	j = 0;
	while (str[j])
	{
		if (j > 0 && str[j - 1] == '=')
		{
			s[i++] = '\"';
			len = 1;
		}
		s[i++] = str[j++];
	}
	if (len)
		s[i++] = '\"';
	s[i] = '\0';
	free(str);
	return (s);
}

static void	ft_copy_env(t_struct *env)
{
	t_list	*tmp;

	tmp = env->s_env;
	while (tmp)
	{
		ft_lstadd_back(&env->s_exp,
			ft_lstnew(ft_str_export(ft_strdup(tmp->content)), tmp->flag));
		tmp = tmp->next;
	}
}

static void	ft_sort_exp(t_struct *env)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = 0;
	tmp = env->s_exp;
	while (tmp->next)
	{
		tmp2 = tmp->next;
		while (tmp2->next)
		{
			if (ft_strcmp(tmp->content, tmp2->content) > 0)
				ft_swap_list(&tmp->content, &tmp2->content);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

void	ft_print_exp(t_struct *env, t_list1 *fd)
{
	t_list	*tmp;

	ft_copy_env(env);
	ft_sort_exp(env);
	tmp = env->s_exp;
	while (tmp)
	{
		write(fd->fd[1], "declare -x ", 11);
		write(fd->fd[1], tmp->content, ft_strlen(tmp->content));
		write(fd->fd[1], "\n", 1);
		tmp = tmp->next;
	}
	ft_lstclear(&(env->s_exp), free);
}
