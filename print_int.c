#include "ft_printf.h"

int	print_int(int n)
{
	if (n < -9)
		return (print_int(n / 10) + print_int(-(n % 10)));
	else if (n < 0)
		return (print_char('-') + print_int(-n));
	else if (n > 9)
		return (print_int(n / 10) + print_int(n % 10));
	return (print_char('0' + n));
}
