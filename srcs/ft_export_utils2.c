#include "../minishell.h"

int	ft_check_first_letter(char c)
{
	if ((c > 64 && c < 91) || (c > 96 && c < 123) || c == 95)
		return (1);
	return (0);
}

int	ft_check_sym(char c)
{
	if ((c > 64 && c < 91) || (c > 96 && c < 123)
		|| c == 95 || (c > 48 && c < 58))
		return (1);
	return (0);
}

int	ft_check_name(char *str)
{
	int	i;

	if (ft_check_first_letter(str[0]))
	{
		i = 1;
		while (str[i])
		{
			if (!ft_check_sym(str[i]))
				return (1);
			i++;
		}
		return (0);
	}
	return (1);
}

void	ft_add_elem(t_struct *env, int len, char *str)
{
	if (len > 1)
		len = 1;
	else
		len = 0;
	if (!ft_search_elem(env, str))
	{
		ft_lstadd_back(&(env)->s_env, ft_lstnew(ft_strdup(str), len));
		ft_lstclear(&(env->s_exp), free);
	}
}

void	ft_add_env(t_struct *env, t_list1 *fd)
{
	char	**tmp;
	int		len;
	int		i;

	i = 1;
	while (fd->temporary[i])
	{
		if (!ft_strcmp(fd->temporary[i], "="))
			printf("minishell: export: `=': not a valid identifier\n");
		else
		{
			tmp = ft_split(fd->temporary[i], '=');
			len = ft_arraylen(tmp);
			if (!ft_check_name(tmp[0]) && len < 3)
				ft_add_elem(env, len, fd->temporary[i]);
			else
				printf("minishell: export: `%s':not a valid identifier\n",
					fd->temporary[i]);
			ft_free(tmp);
		}
		i++;
	}
}
