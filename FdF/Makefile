SRCS = main.c parsing.c drawline.c convert.c isometric.c colors.c hooks.c
OBJS = $(SRCS:.c=.o)
NAME = FdF
CFLAGS = -Wextra -Werror -Wall
CC = gcc
CLIB = -lmlx -framework OpenGl -framework Appkit -Imlx
LIBFT=	make -C ./libft

all : $(NAME)

$(NAME) : $(SRCS)
	$(LIBFT)
	$(CC) $(CFLAGS) $(CLIB) $(SRCS) -Llibft -lft  -o $(NAME)
#install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

#bonus: Flag_f

Flag_f: $(SRCS_B)
	$(LIBFT)
	$(CC) $(CFLAGS) $(CLIB) $(SRCS) -Llibft -lft  -o $(NAME)
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

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus