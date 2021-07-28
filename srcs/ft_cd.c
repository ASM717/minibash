#include "../minishell.h"

static void	ft_get_update(t_list *tmp, char **tmp2, char *str)
{
	char	**tmp3;

	tmp3 = 0;
	if (ft_strncmp(tmp->content, "PWD=", 4) == 0)
	{
		*tmp2 = ft_strdup(tmp->content);
		free(tmp->content);
		tmp->content = ft_strjoin("PWD=", str);
	}
	else if (tmp2 && ft_strncmp(tmp->content, "OLDPWD=", 7) == 0)
	{
		free(tmp->content);
		tmp3 = ft_split(*tmp2, '=');
		tmp->content = ft_strjoin("OLDPWD=", tmp3[1]);
		free(*tmp2);
		ft_free(tmp3);
	}
}

static void	ft_update_pwd(t_struct *env)
{
	t_list	*tmp;
	char	*tmp2;
	char	str[1024];

	tmp = env->s_env;
	tmp2 = 0;
	getcwd(str, sizeof(str));
	while (tmp)
	{
		ft_get_update(tmp, &tmp2, str);
		tmp = tmp->next;
	}
}

static int	ft_chdirerror(t_struct *env, t_list1 *fd, char *str)
{
	if (chdir(fd->temporary[1]) == -1)
	{
		printf("minishell: %s: %s: No such file or directory\n",
			fd->temporary[0], fd->temporary[1]);
		g_status = 1;
		chdir(str);
		free(str);
		ft_update_pwd(env);
		return (-1);
	}
	return (0);
}

static int	ft_cd_utils(t_struct *env, t_list1 *fd, char *str)
{
	char	*s;

	s = 0;
	if (fd->temporary[1][0] == '~')
	{
		if (fd->temporary[1][1] == '/')
		{
			s = fd->temporary[1];
			fd->temporary[1] = ft_strjoin(getenv("HOME"), &fd->temporary[1][1]);
			free(s);
		}
		else if (fd->temporary[1][1] == 0)
		{
			chdir(getenv("HOME"));
			free(str);
			ft_update_pwd(env);
			return (1);
		}
	}
	return (0);
}

int	ft_cd(t_struct *env, t_list1 *fd)
{
	char	*str;
	int		res;

	res = 0;
	if (fd->temporary[1] == 0)
	{
		chdir(getenv("HOME"));
		ft_update_pwd(env);
		return (1);
	}
	str = getcwd(0, 0);
	res = ft_cd_utils(env, fd, str);
	if (!res)
		res = ft_chdirerror(env, fd, str);
	if (res)
		return (res);
	if (str)
		free(str);
	ft_update_pwd(env);
	return (1);
}
