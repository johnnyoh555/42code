CC			= cc
CFLAGS		= -Wall -Wextra -Werror
SRCS		= ft_printf.c ft_itoa.c ft_convert.c format_x.c format_u.c \
format_p.c format_di.c format_cs.c utils.c check_watershed.c
SRCS_B		= ft_printf_bonus.c ft_itoa_bonus.c ft_convert_bonus.c \
format_x_bonus.c format_u_bonus.c format_p_bonus.c format_di_bonus.c \
format_cs_bonus.c utils_bonus.c check_watershed_bonus.c
OBJ			= $(SRCS:.c=.o)
OBJ_B		= $(SRCS_B:.c=.o)
NAME		= libftprintf.a

all	: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $^

bonus : FLAG

FLAG : $(OBJ_B)
	ar rc $(NAME) $^
	@touch $@

$(OBJ): $(SRCS)
	$(CC) $(CFLAGS) -c $^

$(OBJ_B) : $(SRCS_B)
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_B)
	@rm -f FLAG

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus