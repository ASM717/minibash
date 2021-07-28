#include "libft.h"

char	*ft_space(char *str)
{
	int	i;
	int	j;
	int	len;

	if (!str)
		return (0);
	i = 0;
	len = ft_strlen(str);
	if (str[i] == 32)
	{
		while (str[i] && str[i] == 32)
			i++;
	}
	j = len - 1;
	if (str[j] == 32)
	{
		while (str[j] && str[j] == 32)
			j--;
	}
	if (i == 0 && j + 1 == len)
		return (ft_strdup(str));
	return (ft_substr(str, i, j + 1));
}
