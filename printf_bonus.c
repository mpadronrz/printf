#include "ft_printf_bonus.h"

int	print_ar(va_list ar, char tp, t_flags flags)
{
	int	bytes;

	bytes = 0;
	if (tp == '%')
		bytes = print_char('%');
	else if (tp == 'c')
		bytes = print_char_flags((unsigned char)va_arg(ar, int), flags);
	else if (tp == 's')
		bytes = print_str_flags(va_arg(ar, char *), flags);
	else if (tp == 'i' || tp == 'd')
		bytes = print_int_flags(va_arg(ar, int), flags);
	else if (tp == 'p')
		bytes = print_ptr_flags(va_arg(ar, void *), flags);
	else if (tp == 'u')
		bytes = print_un_flags(va_arg(ar, unsigned int), flags);
	else if (tp == 'x' || tp == 'X')
		bytes = print_hex_flags(va_arg(ar, unsigned int), tp, flags);
	return (bytes);
}

int	ft_printf(const char *str, ...)
{
	va_list	ar;
	t_flags	flags;
	int		bytes;

	flag_reset(&flags);
	if (!str)
		return (-1);
	va_start(ar, str);
	bytes = 0;
	while (*str)
	{
		if (*str != '%')
			bytes += print_char(*str);
		else
		{
			read_flags(&str, &flags);
			bytes += print_ar(ar, *str, flags);
			flag_reset(&flags);
		}
		str ++;
	}
	va_end(ar);
	return (bytes);
}
