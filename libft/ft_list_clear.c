#include "libft.h"

static void	ft_clear_int(t_list1 *list)
{
	list->i = 0;
	list->builtins = 0;
	list->dr = 0;
	list->sr = 0;
	list->dl = 0;
	list->sl = 0;
	list->pid = 0;
	list->pipe = 0;
	list->fd[0] = 0;
	list->fd[1] = 0;
}

void	ft_list_clear(t_list1 *list, void (*del)(void *))
{
	if (list)
	{
		if (list->command)
			del(list->command);
		if (list->redcom)
			del(list->redcom);
		if (list->redirect_command)
			ft_free(list->redirect_command);
		if (list->temporary)
			ft_free(list->temporary);
		if (list->dir)
			ft_free(list->dir);
		ft_clear_int(list);
		free(list);
	}
}
