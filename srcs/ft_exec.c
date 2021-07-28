#include "../minishell.h"

static void	ft_check_fd(t_list1 *tmp)
{
	if (tmp->dr == 1)
	{
		dup2(tmp->fd[1], 1);
		close(tmp->fd[1]);
	}
	else if (tmp->sr == 1)
	{
		dup2(tmp->fd[1], 1);
		close(tmp->fd[1]);
	}
	else if (tmp->dl == 1)
	{
		dup2(tmp->fd[0], 0);
		close(tmp->fd[0]);
	}
	else if (tmp->sl == 1)
	{
		dup2(tmp->fd[0], 0);
		close(tmp->fd[0]);
	}
	else
	{
		dup2(tmp->fd[0], 0);
		dup2(tmp->fd[1], 1);
	}
}

static void	ft_exec_status(t_struct *env, t_list1 *tmp)
{
	if (tmp->builtins)
	{
		ft_buildins(env, tmp);
		ft_clean(env);
	}
	else
	{
		ft_check_fd(tmp);
		if (tmp->temporary && tmp->dir && !g_status)
			execve(tmp->dir[tmp->i],
				tmp->temporary, env->env_array);
		else
		{
			printf("minishell: %s: No such file or directory\n",
				tmp->temporary[0]);
			g_status = 127;
		}
		ft_clean(env);
	}
	exit(g_status);
}

static void	ft_fork_execve(t_struct *env, t_list1 *tmp)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		ft_clean(env);
		exit(-1);
	}
	else if (!pid)
		ft_exec_status(env, tmp);
	else
	{
		waitpid(pid, &g_status, 0);
		g_status = WEXITSTATUS(g_status);
		if (WIFEXITED(g_status))
			env->flag_status = 1;
	}
}

void	ft_exec(t_struct *env, t_list1 *tmp)
{
	int	flag;

	flag = 1;
	if (!env->count_pipe && tmp->builtins)
		ft_buildins_one(env, tmp, &flag);
	if (flag)
		ft_fork_execve(env, tmp);
}
