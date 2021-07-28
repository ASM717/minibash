#include "../minishell.h"

static void	ft_dr(char **s, int *i, t_list1 *tmp)
{
	s = ft_split(tmp->redirect_command[*i], '>');
	ft_double_right(ft_space(s[0]), tmp);
	(*i)++;
	ft_free(s);
}

static void	ft_sr(char	**s, int *i, t_list1 *tmp)
{
	s = ft_split(tmp->redirect_command[*i], '>');
	ft_single_right(ft_space(s[0]), tmp);
	ft_free(s);
}

static void	ft_dl(char **s, int *i, t_list1 *tmp)
{
	s = ft_split(tmp->redirect_command[*i], '<');
	ft_double_left(ft_space(s[0]), tmp);
	(*i)++;
	ft_free(s);
}

static void	ft_sl(char **s, int *i, t_list1 *tmp)
{
	s = ft_split(tmp->redirect_command[*i], '<');
	ft_single_left(ft_space(s[0]), tmp);
	ft_free(s);
}

void	ft_process_redirect(t_list1 *tmp)
{
	int		i;
	char	**s;

	i = 0;
	s = 0;
	while (tmp->redirect_command[i])
	{
		if (ft_strncmp(tmp->redirect_command[i], ">>", 2) == 0)
			ft_dr(s, &i, tmp);
		else if (ft_strncmp(tmp->redirect_command[i], ">", 1) == 0)
			ft_sr(s, &i, tmp);
		else if (ft_strncmp(tmp->redirect_command[i], "<<", 2) == 0)
			ft_dl(s, &i, tmp);
		else if (ft_strncmp(tmp->redirect_command[i], "<", 1) == 0)
			ft_sl(s, &i, tmp);
		i++;
	}
}
