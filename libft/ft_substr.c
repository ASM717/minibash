#include "libft.h"

char	*ft_substr(char *s, int start, int len)
{
	char	*str;
	char	*tmp;
	int		count;

	if (!s)
		return (0);
	count = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	tmp = str;
	while (s[start] && start < len)
		*str++ = s[start++];
	*str = '\0';
	return (tmp);
}
