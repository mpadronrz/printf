#include "ft_printf.h"

int	print_un(unsigned int n)
{
	if (n > 9)
		return (print_un(n / 10) + print_un(n % 10));
	return (print_char('0' + n));
}
