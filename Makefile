NAME = libftprintf.a

CC = cc -c

FLAGS = -Wall -Wextra -Werror -g3

SRCS = printf.c print_char.c print_hex.c print_int.c \
	   print_ptr.c print_str.c print_un.c

NORMAL_OBJS = $(SRCS:.c=.o)

BONUS_SRCS = printf_bonus.c print_char_bonus.c print_hex_bonus.c print_int_bonus.c \
       print_ptr_bonus.c print_str_bonus.c print_un_bonus.c flags_bonus.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

ifeq ($(MAKECMDGOALS),bonus)
HEADER = ft_printf_bonus.h
OBJS = $(BONUS_OBJS)
else
HEADER =ft_printf.h
OBJS = $(NORMAL_OBJS)
endif

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJS)
	@if [ -f $(NAME) ]; then \
		if ar t $(NAME) | grep -q "_bonus"; then \
			if [ "$(MAKECMDGOALS)" != "bonus" ]; then \
				echo "Switching to normal: removing bonus objects and archive"; \
				rm -f $(BONUS_OBJS) $(NAME); \
			fi; \
		else \
			if [ "$(MAKECMDGOALS)" = "bonus" ]; then \
				echo "Switching to bonus: removing normal objects and archive"; \
				rm -f $(NORMAL_OBJS) $(NAME); \
			fi; \
		fi; \
	fi;
	ar crs $(NAME) $(OBJS)

%.o: %.c Makefile $(HEADER)
	$(CC) $(FLAGS) $< -o $@

clean:
	rm -f $(NORMAL_OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean bonus re
