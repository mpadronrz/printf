#include "ft_printf.h"

int	ft_putnbr_hex(unsigned int n, char *base)
{
	if (n > 15)
		return (ft_putnbr_hex(n / 16, base) + ft_putnbr_hex(n % 16, base));
	return (print_char(base[n]));
}

int	print_hex(unsigned int n, char c)
{
	char	*base;

	if (c == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	return (ft_putnbr_hex(n, base));
}
