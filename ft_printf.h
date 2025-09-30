#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	print_char(char c);
int	print_str(char *s);
int	print_int(int n);
int	print_un(unsigned int n);
int	print_ptr(void *ptr);
int	print_hex(unsigned int n, char c);
int	ft_printf(const char *str, ...);
#endif
