#include "ft_printf_bonus.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len ++;
	return (len);
}

int	print_str(char *s, int len)
{
	int	i;

	i = 0;
	while (i < len)
		i += print_char(s[i]);
	return (len);
}

void	print_str_padded(char *s, t_flags flags, int pad_len, int len)
{
	if (!flags.left)
	{
		while (pad_len > 0)
		{
			print_char(' ');
			pad_len --;
		}
	}
	print_str(s, len);
	if (flags.left)
	{
		while (pad_len > 0)
		{
			print_char(' ');
			pad_len --;
		}
	}
}

int	print_str_flags(char *s, t_flags flags)
{
	int		len;

	if (!s)
	{
		if (flags.dot && flags.prec < 6)
			return (print_str_flags("", flags));
		return (print_str_flags("(null)", flags));
	}
	len = ft_strlen(s);
	if (flags.dot && len > flags.prec)
		len = flags.prec;
	if (len >= flags.mfw)
	{
		print_str(s, len);
		return (len);
	}
	print_str_padded(s, flags, flags.mfw - len, len);
	return (flags.mfw);
}
