SRCS			=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
					ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
					ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_strlen.c \
					ft_split.c ft_split_pipe.c ft_strncmp.c ft_strdup.c ft_strcmp.c \
					ft_arraylen.c ft_substr.c ft_free.c ft_bzero.c ft_strjoin.c ft_strjoin1.c \
					ft_push_back.c ft_new_list.c ft_list_clear.c ft_clear_all_list.c ft_isspace.c \
					ft_space.c ft_malloc.c ft_strchr.c ft_itoa.c ft_atoi.c

OBJS			= $(SRCS:.c=.o)


CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
