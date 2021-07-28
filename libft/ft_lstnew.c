#include "libft.h"

t_list	*ft_lstnew(char *content, int flag)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->content = content;
	list->flag = flag;
	list->next = 0;
	return (list);
}
