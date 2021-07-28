#include "../minishell.h"

int	ft_check_line(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			return (1);
		i++;
	}
	return (0);
}

void	ft_init(t_struct *env)
{
	env->s_exp = 0;
	env->s_com = 0;
	env->env_array = 0;
	env->stroka = 0;
	env->s_cmd_line = 0;
	env->flag_status = 0;
	env->status = 0;
	signal(SIGINT, ft_signal_handler);
	signal(SIGQUIT, ft_signal_quit_handler);
	g_status = 0;
}

void	ft_start_line(t_struct *env)
{
	env->stroka = env->s_cmd_line;
	env->s_cmd_line = ft_space(env->s_cmd_line);
	free(env->stroka);
	g_status = ft_lexer(env);
	if (!g_status)
		ft_parser(env);
	ft_clean(env);
}

void	ft_start(t_struct *env)
{
	env->status = ft_status(env);
	g_status = 0;
	env->count_pipe = 0;
	env->flag_status = 0;
	env->s_cmd_line = readline("minishell $>> ");
	if (env->s_cmd_line == NULL)
	{
		printf("\033[Aminishell $>>  exit\n");
		exit(0);
	}
	add_history(env->s_cmd_line);
	if (ft_strlen(env->s_cmd_line) > 0 && ft_check_line(env->s_cmd_line))
		ft_start_line(env);
	free(env->s_cmd_line);
}

int	main(int argc, char **argv, char **envv)
{
	t_struct	*env;

	env = (t_struct *)malloc(sizeof(t_struct));
	if (!env)
		return (1);
	env->s_env = ft_init_env(envv);
	ft_shell_lvl(env);
	if (argc != 1)
	{
		printf("minishell: %s: No such file or directory\n", argv[1]);
		return (1);
	}
	ft_init(env);
	while (1)
		ft_start(env);
	return (ft_status(env));
}
