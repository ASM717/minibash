NAME		= minishell

SRC			= main.c ft_export.c ft_env.c ft_unset.c ft_parser.c \
			ft_echo.c ft_cd.c ft_pwd.c ft_exit.c ft_pipe.c ft_exec.c \
			ft_redirect.c ft_redirect_utils.c ft_parser_utils.c ft_lexer.c \
			ft_buildins.c ft_shlvl.c ft_dollar.c ft_signals.c ft_parser_utils2.c \
			ft_parser_utils3.c ft_export_utils.c ft_export_utils2.c ft_dollar_utils.c \
			ft_parser_utils4.c ft_export_utils3.c ft_status.c ft_parser_utils5.c \
			ft_lexer_utils.c

SRCS		= $(addprefix srcs/, $(SRC))

OBJS		= $(SRCS:.c=.o)

CC			= gcc

INC			= -I. -Ilibft

FLAGS		= -Wall -Wextra -Werror  -g $(INC)

READLFLAG	= -L/Users/amuriel/.brew/Cellar/readline/8.1/lib/ \
			-I/Users/amuriel/.brew/Cellar/readline/8.1/include \
			-lreadline
LIBFT		= -L libft -lft


$(NAME):$(OBJS) minishell.h ./libft/libft.h
	@make -C ./libft
	@$(CC) ${FLAGS} ${READLFLAG} ${SRCS} ${LIBFT} -o ${NAME}
	@echo "\033[0;33m\t>>>>>Compile minishell done!<<<<"

all:$(NAME)


clean:
	@/bin/rm -f $(OBJS)
	@make clean -C ./libft
	@echo "\033[0;33m>>>Clean .o files done!<<<"

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C ./libft
	@echo "\033[0;33m>>>Clean all files done!<<<"

re: fclean all

norm :
	norminette *.h ./libft/*.c ./libft/*.h ./srcs/*.c

.PHONY: all clean fclean re norm
