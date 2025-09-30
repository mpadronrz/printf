#include "ft_printf_bonus.h"

int	ft_hexlen(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len ++;
		n /= 16;
	}
	return (len);
}

int	ft_putnbr_hex(unsigned int n, char *base)
{
	if (n > 15)
		return (ft_putnbr_hex(n / 16, base) + ft_putnbr_hex(n % 16, base));
	return (print_char(base[n]));
}

int	print_hex(unsigned int n, char c, t_flags flags)
{
	char	*base;

	if (flags.dot && !flags.prec && n == 0)
		return (0);
	if (flags.alt && n != 0)
	{
		print_char('0');
		print_char(c);
	}
	while (flags.aux > 0)
	{
		print_char('0');
		flags.aux--;
	}
	if (c == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	return (ft_putnbr_hex(n, base));
}

void	print_hex_padded(int n, char c, t_flags flags, int pad_len)
{
	char	pad;

	if (!flags.left)
	{
		if (flags.zero && !flags.dot)
			pad = '0';
		else
			pad = ' ';
		while (pad_len-- > 0)
			print_char(pad);
	}
	print_hex(n, c, flags);
	if (flags.left)
	{
		while (pad_len > 0)
		{
			print_char(' ');
			pad_len --;
		}
	}
}

int	print_hex_flags(unsigned int n, char c, t_flags flags)
{
	int	len;

	len = ft_hexlen(n);
	if (flags.dot && flags.prec > len)
	{
		flags.aux = flags.prec - len;
		len = flags.prec;
	}
	if (flags.dot && !flags.prec && n == 0)
		len = 0;
	if (flags.alt && n != 0)
		len += 2;
	if (len >= flags.mfw)
	{
		print_hex(n, c, flags);
		return (len);
	}
	print_hex_padded(n, c, flags, flags.mfw - len);
	return (flags.mfw);
}
