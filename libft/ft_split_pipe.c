#include "libft.h"

static void	ft_word_count_norm(char **s, int *quote_flag, char *c, int *flag)
{
	if (*(*s) == 34 && !(*quote_flag))
		*quote_flag = 1;
	else if (*(*s) == 34 && *quote_flag)
		*quote_flag = 0;
	if (*(*s) == 39 && !(*quote_flag))
		*quote_flag = 1;
	else if (*(*s) == 39 && *quote_flag)
		*quote_flag = 0;
	if (*(*s) == *c && !(*quote_flag) && *flag == 1)
		*flag = 0;
}

static int	ft_word_count(char *s, char c)
{
	int	count;
	int	flag;
	int	quote_flag;

	count = 0;
	flag = 0;
	quote_flag = 0;
	while (*s)
	{
		if (flag == 0 && *s != 34 && *s != 39 && *s != c && *s)
		{
			flag = 1;
			count++;
		}
		ft_word_count_norm(&s, &quote_flag, &c, &flag);
		s++;
	}
	return (count);
}

static int	ft_len(char *s, char c)
{
	int	len;
	int	flag;

	len = 0;
	flag = 0;
	while (*s && (*s != c || flag))
	{
		if (*s == 34 && !flag)
			flag = 1;
		else if (*s == 34 && flag)
			flag = 0;
		if (*s == 39 && !flag)
			flag = 1;
		else if (*s == 39 && flag)
			flag = 0;
		len++;
		s++;
	}
	return (len);
}

static void	ft_split_pipe_norm(char **str, char **s, int *i, int *j)
{
	if (*(*s) == '\"')
	{
		str[*i][(*j)++] = *(*s)++;
		while (*(*s) != '\"' && *(*s))
			str[*i][(*j)++] = *(*s)++;
		if (*(*s) == '\"')
			str[*i][(*j)++] = *(*s)++;
	}
	else if (*(*s) == '\'')
	{
		str[*i][(*j)++] = *(*s)++;
		while (*(*s) != '\'' && *(*s))
			str[*i][(*j)++] = *(*s)++;
		if (*(*s) == '\'')
			str[*i][(*j)++] = *(*s)++;
	}
	else
		str[*i][(*j)++] = *(*s)++;
}

char	**ft_split_pipe(char *s, char c)
{
	char	**str;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	str = (char **)malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			str[i] = (char *)malloc(sizeof(char) * (ft_len(s, c) + 1));
			j = 0;
			while (*s && *s != c)
				ft_split_pipe_norm(str, &s, &i, &j);
			str[i][j] = '\0';
			i++;
		}
	}
	str[i] = NULL;
	return (str);
}
