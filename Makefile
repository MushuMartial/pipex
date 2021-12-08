NAME = pipex

SRCS = pipex.c

OBJS = $(SRCS:.c=.o)

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS)  -o $(NAME)

all:	$(NAME)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all