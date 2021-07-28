#include "../minishell.h"

void	ft_pipe(t_struct *env, t_list1 *tmp)
{
	int		fd[2];
	pid_t	pid;

	pipe(fd);
	pid = fork();
	if (pid == -1)
	{
		ft_clean(env);
		exit(-1);
	}
	else if (pid == 0)
	{
		dup2(fd[1], 1);
		close(fd[0]);
		ft_exec(env, tmp);
		close(fd[1]);
		exit(1);
	}
	else
	{
		dup2(fd[0], 0);
		close(fd[0]);
		close(fd[1]);
	}
}

void	ft_pipe_start(t_struct *env)
{
	t_list1	*tmp;
	int		fd0;

	tmp = env->s_com;
	fd0 = dup(0);
	while (tmp->pipe && !g_status)
	{
		ft_pipe(env, tmp);
		tmp = tmp->next;
	}
	ft_exec(env, tmp);
	dup2(fd0, 0);
	if (env->env_array)
	{
		ft_free(env->env_array);
		env->env_array = 0;
	}
	while (wait(NULL) > 0)
		;
}
