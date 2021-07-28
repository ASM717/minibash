#include "libft.h"

static const char	*ft_is_pass(const char *str)
{
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == 32)
		str++;
	return (str);
}

int	ft_atoi(const char *str)
{
	int			sign;
	long long	res;

	res = 0;
	sign = 1;
	str = ft_is_pass(str);
	if (*str == '-')
	{
		sign = -sign;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str > 47 && *str < 58)
	{
		if ((LLONG_MAX - res) < ((int)(*str - 48)) && sign > 0)
			return (-1);
		if ((LLONG_MAX - res) < ((int)(*str - 48) - 1) && sign < 0)
			return (0);
		res = 10 * res + (*str - 48);
		str++;
	}
	return (res * sign);
}
