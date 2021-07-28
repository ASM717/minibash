#include "../minishell.h"

void	ft_print_echo(int i, t_list1 *fd)
{
	while (i < ft_arraylen(fd->temporary) - 1)
	{
		write(fd->fd[1], fd->temporary[i], ft_strlen(fd->temporary[i]));
		write(fd->fd[1], " ", 1);
		i++;
	}
	write(fd->fd[1], fd->temporary[i], ft_strlen(fd->temporary[i]));
}

int	ft_echo(t_list1 *fd)
{
	if (ft_strcmp(fd->temporary[0], "echo"))
	{
		write(fd->fd[1], "minishell: ", 11);
		write(fd->fd[1], fd->temporary[0], ft_strlen(fd->temporary[0]));
		write(fd->fd[1], ": command not found\n", 20);
		g_status = 127;
		return (g_status);
	}
	if (!fd->temporary[1])
		write(fd->fd[1], "\n", 1);
	else if (ft_strcmp(fd->temporary[1], "-n") == 0)
	{
		if (!fd->temporary[2])
			write(fd->fd[1], "", 1);
		else
			ft_print_echo(2, fd);
	}
	else
	{
		ft_print_echo(1, fd);
		write(fd->fd[1], "\n", 1);
	}
	close(fd->fd[1]);
	return (0);
}
