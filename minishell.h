#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <signal.h>
# include <fcntl.h>
# include <limits.h>

int	g_status;

typedef struct s_struct
{
	t_list	*s_env;
	t_list	*s_exp;
	t_list1	*s_com;
	char	**env_array;
	char	*s_cmd_line;
	char	*stroka;
	int		count_pipe;
	int		status;
	int		flag_status;
}t_struct;

typedef struct s_shlvl
{
	int			lvl_num;
	char		*lvl;
	char		*tmp;
	char		*value;
	char		*lvl_str;
}t_shlvl;

t_list	*ft_init_env(char **envv);
void	ft_print_env(t_struct *env, t_list1 *fd);
void	ft_export(t_struct *env, t_list1 *fd);
void	ft_unset(t_struct *env, t_list1 *fd);
void	ft_parser(t_struct *env);
void	ft_name_quotes1(t_list1 *tmp);
void	ft_name_quotes2(t_list1 *tmp);
int		ft_check_buildins(char *str);
void	ft_buildins_one(t_struct *env, t_list1 *fd, int	*flag);
void	ft_buildins(t_struct *env, t_list1 *fd);
int		ft_echo(t_list1 *fd);
void	ft_pwd(t_list1 *fd);
int		ft_cd(t_struct *env, t_list1 *fd);
void	ft_pipe(t_struct *env, t_list1 *tmp);
void	ft_exec(t_struct *env, t_list1 *tmp);
void	ft_process_redirect(t_list1 *tmp);
void	ft_double_right(char *str, t_list1 *tmp);
void	ft_single_right(char *str, t_list1 *tmp);
void	ft_double_left(char *str, t_list1 *tmp);
void	ft_single_left(char *str, t_list1 *tmp);
char	**ft_make_array(t_struct *env);
char	*ft_space(char *str);
void	ft_pipe_start(t_struct *env);
char	**ft_make_array(t_struct *env);
int		ft_lexer(t_struct *env);
void	ft_clean(t_struct *env);
void	ft_shell_lvl(t_struct *env);
void	ft_signal_handler(int signal);
void	ft_signal_quit_handler(int signal);
void	ft_check_dollar(t_list1 *tmp, t_struct *env);
void	ft_exit(t_list1 *fd);
void	ft_redirect_split_out(t_list1 *tmp);
void	ft_get_path_param(t_list1 *tmp);
void	ft_check_valid_path(t_list1 *tmp);
void	ft_find_path(t_list1 *tmp, char **path_arr);
t_list1	*ft_make_list(t_struct *env);
int		ft_check_end(char *str, int i);
int		ft_is_redirect(char *s);
void	ft_redirect_check_out(t_list1 *tmp);
int		ft_find_redirection(char *str);
void	ft_pass_quote(int *i, char *str);
int		ft_flag(int flag);
void	ft_print_exp(t_struct *env, t_list1 *fd);
void	ft_add_env(t_struct *env, t_list1 *fd);
char	*ft_check_dollar2(char *s, t_struct *env);
char	*ft_status_dollar(char *str, int i, t_struct *env);
int		ft_check_finish(char *str, int start);
char	*ft_dollar_change(char *str, int start, int finish, t_struct *env);
int		ft_search_elem(t_struct *env, char *str);
int		ft_status(t_struct *env);
int		ft_check_stupid(char *str);
int		ft_check_line(char *str);
char	*ft_getenv(t_struct *env);
int		ft_check_stupid_input(t_list1 *tmp);
int		ft_check_space(char *str, char c);
int		ft_checker_space(char *str);
void	ft_norm_check_pipe(int i, int *flag, char *str, char c);
int		ft_check_norm_red(int i, int *flag, char *str, char c);

#endif
