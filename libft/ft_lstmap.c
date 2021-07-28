#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*list2;

	list = 0;
	while (lst)
	{
		list2 = ft_lstnew(f(lst->content), 1);
		if (!list2)
		{
			ft_lstclear(&list, del);
			return (0);
		}
		ft_lstadd_back(&list, list2);
		lst = lst->next;
	}
	return (list);
}
