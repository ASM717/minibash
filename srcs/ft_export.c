#include "../minishell.h"

void	ft_export(t_struct *env, t_list1 *fd)
{
	int		len;

	len = ft_arraylen(fd->temporary);
	if (len > 1)
		ft_add_env(env, fd);
	else if (len == 1)
		ft_print_exp(env, fd);
}
