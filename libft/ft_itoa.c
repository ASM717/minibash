#include "libft.h"

static size_t	ft_count(int n)
{
	size_t	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static size_t	ft_ternar(int n, size_t num)
{
	if (n < 0)
		return (-num);
	return (num);
}

static size_t	ft_ternar2(int n)
{
	if (n < 0)
		return (ft_count(n) + 1);
	return (ft_count(n));
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	num;
	size_t	count;

	num = n;
	num = ft_ternar(n, num);
	count = ft_ternar2(n);
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	str[count] = '\0';
	while (count--)
	{
		str[count] = num % 10 + 48;
		num /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
