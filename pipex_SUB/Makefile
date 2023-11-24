CC= cc
CFLAGS= -Wall -Wextra -Werror
SRCS= main.c pipes.c path_cmd.c childs.c utils.c here_doc.c
SRCS_B= main_bonus.c pipes_bonus.c path_cmd_bonus.c childs_bonus.c utils_bonus.c here_doc_bonus.c
OBJ_B= $(SRCS_B:.c=.o)
NAME= pipex
LIBFT=	make -C ./libft

all: $(NAME)

$(NAME): $(SRCS)
	$(LIBFT)
	$(CC) $(CFLAGS) $(SRCS) -Llibft -lft -o $(NAME) 

bonus: Flag_f

Flag_f: $(SRCS_B)
	$(LIBFT)
	$(CC) $(CFLAGS) $(SRCS_B) -Llibft -lft -o $(NAME)
	touch $@

$(OBJ): $(SRCS)
	$(CC) $(CFLAGS) -c $^

$(OBJ_B): $(SRCS_B)
	$(CC) $(CFLAGS) -c $^
	
clean:
	rm -f $(OBJ)
	rm -f $(OBJ_B)
	rm -f Flag_f
	$(LIBFT) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: bonus all clean fclean re