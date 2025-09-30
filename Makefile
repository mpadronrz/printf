NAME = libftprintf.a

CC = cc -c

FLAGS = -Wall -Wextra -Werror -g3

SRCS = printf.c print_char.c print_hex.c print_int.c \
	   print_ptr.c print_str.c print_un.c

OBJS = $(SRCS:.c=.o)

BONUS_SRCS = printf_bonus.c print_char_bonus.c print_hex_bonus.c print_int_bonus.c \
       print_ptr_bonus.c print_str_bonus.c print_un_bonus.c flags_bonus.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar cr $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

bonus: fclean $(BONUS_OBJS)
	ar cr $(NAME) $(BONUS_OBJS)

re: fclean all

.PHONY: all clean fclean bonus re
