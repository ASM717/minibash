#include "../minishell.h"

int	ft_check_buildins(char *str)
{
	if (ft_strcmp(str, "env") == 0)
		return (1);
	else if (ft_strcmp(str, "export") == 0)
		return (1);
	else if (ft_strcmp(str, "unset") == 0)
		return (1);
	else if (ft_strcmp(str, "echo") == 0)
		return (1);
	else if (ft_strcmp(str, "cd") == 0)
		return (1);
	else if (ft_strcmp(str, "pwd") == 0)
		return (1);
	else if (ft_strcmp(str, "exit") == 0)
		return (1);
	return (0);
}

void	ft_buildins_one(t_struct *env, t_list1 *fd, int *flag)
{
	*flag = 0;
	if (ft_strcmp(fd->temporary[0], "env") == 0)
		ft_print_env(env, fd);
	else if (ft_strcmp(fd->temporary[0], "export") == 0)
		ft_export(env, fd);
	else if (ft_strcmp(fd->temporary[0], "unset") == 0)
		ft_unset(env, fd);
	else if (ft_strcmp(fd->temporary[0], "cd") == 0)
		ft_cd(env, fd);
	else if (ft_strcmp(fd->temporary[0], "pwd") == 0)
		ft_pwd(fd);
	else if (ft_strcmp(fd->temporary[0], "exit") == 0)
		ft_exit(fd);
	else
		*flag = 1;
}

void	ft_buildins(t_struct *env, t_list1 *fd)
{
	if (ft_strcmp(fd->temporary[0], "env") == 0)
		ft_print_env(env, fd);
	else if (ft_strcmp(fd->temporary[0], "export") == 0)
		ft_export(env, fd);
	else if (ft_strcmp(fd->temporary[0], "unset") == 0)
		ft_unset(env, fd);
	else if (ft_strcmp(fd->temporary[0], "echo") == 0)
		ft_echo(fd);
	else if (ft_strcmp(fd->temporary[0], "cd") == 0)
		ft_cd(env, fd);
	if (ft_strcmp(fd->temporary[0], "pwd") == 0)
		ft_pwd(fd);
	if (ft_strcmp(fd->temporary[0], "exit") == 0)
		ft_exit(fd);
}
