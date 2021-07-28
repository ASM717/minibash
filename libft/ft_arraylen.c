#include "libft.h"

int	ft_arraylen(char **str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		count++;
		i++;
	}
	return (i);
}
