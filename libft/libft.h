#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list1
{
	char			*command;
	char			*redcom;
	char			**redirect_command;
	char			**dir;
	char			**temporary;
	int				i;
	int				builtins;
	int				dr;
	int				sr;
	int				dl;
	int				sl;
	int				pipe;
	pid_t			pid;
	int				fd[2];
	struct s_list1	*next;
	struct s_list1	*prev;
}t_list1;

typedef struct s_list
{
	char			*content;
	int				flag;
	struct s_list	*next;
}t_list;

typedef struct s_split
{
	char	**str;
	int		i;
	int		j;
}t_split;

t_list1	*ft_new_list(char *command, int is_pipe);
void	ft_push_back(t_list1 **lst, t_list1 *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(char *content, int flag);
int		ft_lstsize(t_list *lst);
int		ft_strlen(char *s);
char	**ft_split(char *s, char c);
char	**ft_split_pipe(char *s, char c);
int		ft_strncmp(char *s1, char *s2, int n);
char	*ft_strdup(char *src);
int		ft_strcmp(char *s1, char *s2);
int		ft_arraylen(char **str);
char	*ft_substr(char *s, int start, int len);
void	*ft_free(char **str);
void	ft_bzero(char *s, int n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strjoin1(char *s1, char *s2);
void	ft_list_clear(t_list1 *list, void (*del)(void *));
void	ft_clear_all_list(t_list1 **lst, void (*del)(void *));
int		ft_isspace(char c);
char	*ft_space(char *str);
char	**ft_malloc_array(int len);
int		ft_strchr(char *str, char c);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);

#endif
