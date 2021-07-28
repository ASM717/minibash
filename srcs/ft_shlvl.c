#include "../minishell.h"

static void	ft_shell_lvl_inc(t_list *head, t_shlvl *shlvl)
{
	shlvl->tmp = ft_substr(head->content, 0, 6);
	shlvl->lvl = ft_substr(head->content, 6, ft_strlen(head->content));
	shlvl->lvl_num = ft_atoi(shlvl->lvl);
	free(shlvl->lvl);
	shlvl->lvl_num += 1;
	shlvl->lvl_str = ft_itoa(shlvl->lvl_num);
	shlvl->value = ft_strjoin1(shlvl->tmp, shlvl->lvl_str);
	free(shlvl->lvl_str);
	free(head->content);
	head->content = ft_strdup(shlvl->value);
	free(shlvl->value);
}

void	ft_shell_lvl(t_struct *env)
{
	t_list	*head;
	t_shlvl	*shlvl;

	shlvl = 0;
	head = 0;
	shlvl = (t_shlvl *)malloc(sizeof(t_shlvl));
	head = env->s_env;
	while (head)
	{
		if (ft_strncmp(head->content, "SHLVL=", 6) == 0)
			ft_shell_lvl_inc(head, shlvl);
		head = head->next;
	}
	free(shlvl);
}
