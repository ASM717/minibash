#include "../minishell.h"

void	ft_get_path_command(t_list1	*tmp, t_struct *env)
{
	char	**path_arr;
	char	*str;

	str = ft_getenv(env);
	path_arr = ft_split(str, ':');
	free(str);
	if (!path_arr)
		tmp->dir = 0;
	else
	{
		tmp->dir = ft_malloc_array(ft_arraylen(path_arr) + 2);
		tmp->i = 0;
		ft_find_path(tmp, path_arr);
		ft_free(path_arr);
	}
}

void	ft_command_check_out(t_list1 *tmp, t_struct *env)
{
	tmp->temporary = ft_split_pipe(tmp->command, ' ');
	ft_name_quotes1(tmp);
	ft_check_dollar(tmp, env);
	ft_name_quotes2(tmp);
	if (ft_strncmp(tmp->temporary[0], "./", 2) == 0)
		ft_get_path_param(tmp);
	else if (tmp->temporary[0][0] == '/')
		ft_check_valid_path(tmp);
	else if (ft_check_buildins(tmp->temporary[0]))
		tmp->builtins = 1;
	else
		ft_get_path_command(tmp, env);
}

void	ft_make_list_redirect(t_struct *env)
{
	int		i;
	t_list1	*tmp;

	i = 0;
	tmp = env->s_com;
	while (tmp && !g_status)
	{
		ft_redirect_check_out(tmp);
		if (tmp->redcom)
			ft_redirect_split_out(tmp);
		if (tmp->command && !g_status)
			ft_command_check_out(tmp, env);
		if (tmp->redcom && !g_status)
			ft_process_redirect(tmp);
		tmp = tmp->next;
	}
}

void	ft_init_param(t_struct *env)
{
	env->s_com = ft_make_list(env);
	ft_make_list_redirect(env);
}

void	ft_parser(t_struct *env)
{
	t_list	*tmp;

	tmp = env->s_env;
	ft_init_param(env);
	if (!g_status)
	{
		env->env_array = ft_make_array(env);
		ft_pipe_start(env);
	}
	ft_clean(env);
}
