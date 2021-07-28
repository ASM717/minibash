#include "../minishell.h"

void	ft_double_right(char *str, t_list1 *tmp)
{
	if (str)
	{
		if (tmp->fd[1] != 1)
			close(tmp->fd[1]);
		tmp->fd[1] = open(str, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
		if (tmp->fd[0] < 0)
		{
			g_status = 1;
			printf("minishell: %s: No such file or directory\n", str);
		}
	}
	else
	{
		g_status = 258;
		printf("minishell: syntax error near unexpected token `newline'\n");
	}
	tmp->dr = 1;
	free(str);
}

void	ft_single_right(char *str, t_list1 *tmp)
{
	if (str)
	{
		if (tmp->fd[1] != 1)
			close(tmp->fd[1]);
		tmp->fd[1] = open(str, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
		if (tmp->fd[0] < 0)
		{
			g_status = 1;
			printf("minishell: %s: No such file or directory\n", str);
		}
	}
	else
	{
		g_status = 258;
		printf("minishell: syntax error near unexpected token `newline'\n");
	}
	tmp->sr = 1;
	free(str);
}

static void	ft_heredoc(char *str)
{
	char	*line;
	int		fds;

	fds = open(".tmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (fds < 0)
		g_status = 1;
	line = readline("> ");
	while (g_status != 130 && ft_strcmp((line), str))
	{
		write(fds, line, ft_strlen(line));
		write(fds, "\n", 1);
		free(line);
		line = readline("> ");
	}
	if (g_status == 130)
		g_status = 1;
	free(line);
	close(fds);
}

void	ft_double_left(char *str, t_list1 *tmp)
{
	if (str)
		ft_heredoc(str);
	else
	{
		g_status = 258;
		printf("minishell: syntax error near unexpected token `newline'\n");
	}
	tmp->fd[0] = open(".tmp", O_RDONLY);
	if (tmp->fd[0] < 0)
	{
		g_status = 1;
		printf("minishell: %s: No such file or directory\n", str);
	}
	unlink(".tmp");
	tmp->dl = 1;
	free(str);
}

void	ft_single_left(char *str, t_list1 *tmp)
{
	if (str)
	{
		tmp->fd[0] = open(str, O_RDONLY);
		if (tmp->fd[0] < 0)
		{
			g_status = 1;
			printf("minishell: %s: No such file or directory\n", str);
		}
	}
	else
	{
		g_status = 258;
		printf("minishell: syntax error near unexpected token `newline'\n");
	}
	tmp->sl = 1;
	free(str);
}
