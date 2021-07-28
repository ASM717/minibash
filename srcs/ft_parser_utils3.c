#include "../minishell.h"

char	**ft_make_array(t_struct *env)
{
	char	**array;
	t_list	*tmp;
	int		i;

	tmp = env->s_env;
	i = ft_lstsize(tmp) + 1;
	array = (char **)malloc(sizeof(char *) * i);
	if (!array)
		return (NULL);
	i = 0;
	while (tmp)
	{
		array[i] = ft_strdup(tmp->content);
		i++;
		tmp = tmp->next;
	}
	array[i] = NULL;
	return (array);
}

void	ft_clean(t_struct *env)
{
	(void) env;
	if (env->s_com != 0)
		ft_clear_all_list(&(env->s_com), free);
	if (env->s_exp)
		ft_lstclear(&env->s_exp, free);
	if (env->env_array)
	{
		ft_free(env->env_array);
		env->env_array = 0;
	}
	if (env->s_cmd_line)
	{
		free(env->s_cmd_line);
		env->s_cmd_line = 0;
	}
}

t_list1	*ft_list_add(t_struct *env, char **tmp)
{
	int		i;
	int		len;
	t_list1	*head;

	i = 0;
	len = ft_arraylen(tmp) - 1;
	env->stroka = 0;
	head = env->s_com;
	while (i < len)
	{
		env->stroka = ft_strdup(tmp[i]);
		ft_push_back(&head, ft_new_list(ft_space(env->stroka), 1));
		free(env->stroka);
		env->stroka = 0;
		env->count_pipe++;
		i++;
	}
	env->stroka = ft_strdup(tmp[i]);
	ft_push_back(&head, ft_new_list(ft_space(env->stroka), 0));
	free(env->stroka);
	return (head);
}

t_list1	*ft_make_list(t_struct *env)
{
	char	**tmp;
	t_list1	*head;

	env->s_com = 0;
	tmp = ft_split_pipe(env->s_cmd_line, '|');
	head = ft_list_add(env, tmp);
	ft_free(tmp);
	env->stroka = 0;
	return (head);
}

int	ft_flag(int flag)
{
	if (flag)
		return (1);
	return (0);
}
