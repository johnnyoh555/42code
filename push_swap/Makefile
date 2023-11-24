CC= cc
CFLAGS= -Wall -Wextra -Werror
SRCS= cmd.c change_nbr.c hardcoding.c main.c sorting.c sortprint3.c sortprint4.c utils.c
SRCS_B= main_bonus.c utils_bonus.c cmd_bonus.c
OBJ= $(SRCS:.c=.o)
OBJ_B= $(SRCS_B:.c=.o)
NAME= push_swap
CEC= checker
LIBFT=	make -C ./libft

all	: $(NAME)

$(NAME): $(SRCS)
	$(LIBFT)
	$(CC) $(CFLAGS) $(SRCS) -Llibft -lft -o $(NAME) 

bonus : LAST_bonus

LAST_bonus : $(SRCS_B)
	$(LIBFT)
	$(CC) $(CFLAGS) $(SRCS_B) -Llibft -lft -o $(CEC)
	@touch $@

$(OBJ): $(SRCS)
	$(CC) $(CFLAGS) -c $^

$(OBJ_B): $(SRCS_B)
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_B)
	rm -f LAST_bonus
	$(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(CEC)
	$(LIBFT) fclean

re: fclean all

.PHONY: bonus all clean fclean re