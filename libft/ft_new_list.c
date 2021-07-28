#include "libft.h"

t_list1	*ft_new_list(char *command, int pipe)
{
	t_list1	*list;

	list = (t_list1 *)malloc(sizeof(t_list1));
	if (!list)
		return (NULL);
	list->command = command;
	list->redcom = 0;
	list->redirect_command = 0;
	list->dir = 0;
	list->temporary = 0;
	list->i = 0;
	list->builtins = 0;
	list->dr = 0;
	list->sr = 0;
	list->dl = 0;
	list->sl = 0;
	list->pid = 0;
	list->pipe = pipe;
	list->fd[0] = 0;
	list->fd[1] = 1;
	list->next = 0;
	list->prev = 0;
	return (list);
}
