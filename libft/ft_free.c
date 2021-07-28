#include "libft.h"

void	*ft_free(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
		str = NULL;
	}
	return (NULL);
}
