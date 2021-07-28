#include "../minishell.h"

static void	ft_redirect_split_out2(t_list1 *tmp, int i, char **str, int num)
{
	char	*stroka;
	char	*temp;
	int		j;

	j = 0;
	if (num == 1)
		j = ft_check_end(tmp->redcom, i);
	else if (num == 2)
		j = ft_check_end(tmp->redcom, i + 1);
	stroka = ft_substr(tmp->redcom, i, j);
	temp = ft_strjoin("/", stroka);
	*str = ft_strjoin1(*str, temp);
	free(temp);
	free(stroka);
}

void	ft_redirect_split_out(t_list1 *tmp)
{
	int		i;
	int		num;
	char	*str;

	i = 0;
	str = ft_strdup("");
	while (tmp->redcom[i])
	{
		num = ft_is_redirect(&(tmp->redcom)[i]);
		if (num)
			ft_redirect_split_out2(tmp, i, &str, num);
		i++;
	}
	tmp->redirect_command = ft_split(str, '/');
	free(str);
}

void	ft_get_path_param(t_list1 *tmp)
{
	tmp->dir = ft_malloc_array(2);
	tmp->i = 0;
	tmp->dir[tmp->i] = ft_strdup(tmp->temporary[0]);
	tmp->i = 1;
	tmp->dir[tmp->i] = 0;
	tmp->i = 0;
}

void	ft_check_valid_path(t_list1 *tmp)
{
	struct stat	buf[4096];

	if (!stat(tmp->temporary[0], buf))
	{
		tmp->dir = ft_malloc_array(2);
		tmp->dir[0] = ft_strdup(tmp->temporary[0]);
		tmp->dir[1] = 0;
	}
	else
	{
		g_status = 127;
		printf("minishell: %s: command not found\n", tmp->temporary[0]);
	}
}

void	ft_find_path(t_list1 *tmp, char **path_arr)
{
	char		*s;
	struct stat	buf[4096];

	while (path_arr[tmp->i] && !g_status)
	{
		s = ft_strjoin(path_arr[tmp->i], "/");
		s = ft_strjoin1(s, tmp->temporary[0]);
		tmp->dir[tmp->i] = ft_strdup(s);
		free(s);
		if (!stat(tmp->dir[tmp->i], buf))
		{
			tmp->dir[tmp->i + 1] = NULL;
			break ;
		}
		tmp->i++;
	}
	if (tmp->i >= ft_arraylen(path_arr) - 1)
	{
		g_status = 127;
		printf("minishell: %s: command not found\n", tmp->temporary[0]);
		tmp->dir[tmp->i] = NULL;
	}
	if (!g_status && tmp->dir[tmp->i + 1] != NULL)
		tmp->dir[tmp->i] = NULL;
}
