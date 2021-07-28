#include "libft.h"
#include <stdio.h>

void	ft_push_back(t_list1 **lst, t_list1 *new)
{
	t_list1	*tmp;

	if (!*lst)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}
