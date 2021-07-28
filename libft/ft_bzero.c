#include "libft.h"

void	ft_bzero(char *s, int n)
{
	char	*tmp;

	tmp = (char *)s;
	if (n)
	{
		while (n--)
		{
			*(tmp++) = 0;
		}
	}
}
