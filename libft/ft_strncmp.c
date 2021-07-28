#include "libft.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	if (!s1)
		return (-1);
	while ((*s1 || *s2) && n--)
	{
		if (*s1++ != *s2++)
			return ((unsigned char)*--s1 - (unsigned char)*--s2);
	}
	return (0);
}
