#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_flags
{
	int	mfw;
	int	sign;
	int	space;
	int	alt;
	int	zero;
	int	left;
	int	dot;
	int	prec;
	int	aux;
}	t_flags;

void	flag_reset(t_flags *flags);
void	read_flags(const char **str, t_flags *flags);
int		print_char(char c);
int		print_str(char *s, int len);
int		print_char_flags(char c, t_flags flags);
int		print_str_flags(char *s, t_flags flags);
int		print_int_flags(int n, t_flags flags);
int		print_un_flags(unsigned int n, t_flags flags);
int		print_ptr_flags(void *ptr, t_flags flags);
int		print_hex_flags(unsigned int n, char c, t_flags flags);
int		ft_printf(const char *str, ...);
#endif
