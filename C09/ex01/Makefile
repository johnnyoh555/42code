CC		= cc
INC		= includes
CFLAGS	= -Wall -Wextra -Werror
SRCS	= srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJECTS	= $(SRCS:.c=.o)
NAME	= libft.a

all :  $(NAME)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INC)

$(NAME) : $(OBJECTS)
	ar rc $@ $^

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
