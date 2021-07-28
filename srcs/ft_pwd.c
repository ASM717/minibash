#include "../minishell.h"

void	ft_pwd(t_list1 *fd)
{
	char	cwd[1024];
	char	*tmp;

	tmp = getcwd(cwd, sizeof(cwd));
	if (tmp != NULL)
	{
		write(fd->fd[1], cwd, ft_strlen(cwd));
		write(fd->fd[1], "\n", 1);
	}
}
