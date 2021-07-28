#include "libft.h"

void	ft_clear_all_list(t_list1 **list, void (*del)(void *))
{
	if (list && *list)
	{
		ft_clear_all_list(&(*list)->next, del);
		ft_list_clear(*list, del);
		*list = NULL;
	}
}
