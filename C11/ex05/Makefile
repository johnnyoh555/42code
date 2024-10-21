CC		= cc
INC		= includes
CFLAGS	= -Wall -Wextra -Werror
SRCS	= main.c calculate.c
OBJECTS	= $(SRCS:.c=.o)
NAME	= do-op

all :  $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
