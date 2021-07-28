#include "libft.h"

char	**ft_malloc_array(int len)
{
	char	**str;

	str = (char **)malloc(sizeof(char *) * len);
	if (!str)
		return (NULL);
	return (str);
}
