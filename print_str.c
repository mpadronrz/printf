#include "ft_printf.h"

int	print_str(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (print_str("(null)"));
	while (s[len])
		len += print_char(s[len]);
	return (len);
}
