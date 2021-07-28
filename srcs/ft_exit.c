#include "../minishell.h"

static long long	new_atoi(char *str)
{
	int			i;
	int			sign;
	long long	num;

	i = 0;
	num = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			num = num * 10 + str[i] - '0';
		else
			break ;
		i++;
	}
	return (sign * num);
}

static int	ft_check_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		++i;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		++i;
	}
	return (1);
}

static void	ft_one_arg(t_list1 *fd)
{
	long long	result;

	if (ft_check_num(fd->temporary[1])
		&& (ft_strcmp(fd->temporary[1], "9223372036854775807") <= 0
			|| ft_strcmp(fd->temporary[1], "-9223372036854775808") <= 0))
		result = new_atoi(fd->temporary[1]);
	else
	{
		printf("minishell: exit: %s: numeric argument required\n",
			fd->temporary[1]);
		exit(255);
	}
	g_status = ((256 + result) % 256);
	exit(g_status);
}

static void	ft_more_arg(t_list1 *fd)
{
	if (!(ft_check_num(fd->temporary[2])))
	{
		printf("minishell: exit: %s: numeric argument required\n",
			fd->temporary[1]);
		exit(255);
	}
	g_status = 1;
	printf("minishell: exit: too many arguments\n");
}

void	ft_exit(t_list1 *fd)
{
	int	len;

	printf("exit\n");
	len = ft_arraylen(fd->temporary);
	if (len == 1)
		exit(1);
	if (len == 2 && fd->temporary[1][0] != '\0')
		ft_one_arg(fd);
	if (len > 2)
		ft_more_arg(fd);
}
