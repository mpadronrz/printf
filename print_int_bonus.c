#include "ft_printf_bonus.h"

int	ft_nbrlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len ++;
		n /= 10;
	}
	return (len);
}

int	print_int_abs(int n)
{
	if (n < -9)
		return (print_int_abs(n / 10) + print_int_abs(-(n % 10)));
	else if (n < 0)
		return (print_int_abs(-n));
	else if (n > 9)
		return (print_int_abs(n / 10) + print_int_abs(n % 10));
	return (print_char('0' + n));
}

void	print_int_signed(int n, t_flags flags, int zeros)
{
	if (flags.sign && n >= 0)
		print_char('+');
	else if (flags.space && n >= 0)
		print_char(' ');
	else if (n < 0)
		print_char('-');
	while (zeros > 0)
	{
		print_char('0');
		zeros --;
	}
	if (flags.dot && !flags.prec && n == 0)
		return ;
	print_int_abs(n);
}

void	print_int_padded(int n, t_flags flags, int pad_len, int zeros)
{
	if (!flags.left)
	{
		if (flags.zero && ! flags.dot)
		{
			print_int_signed(n, flags, pad_len);
			return ;
		}
		while (pad_len > 0)
		{
			print_char(' ');
			pad_len --;
		}
	}
	print_int_signed(n, flags, zeros);
	if (flags.left)
	{
		while (pad_len > 0)
		{
			print_char(' ');
			pad_len --;
		}
	}
}

int	print_int_flags(int n, t_flags flags)
{
	int	len;
	int	zeros;

	zeros = 0;
	len = ft_nbrlen(n);
	if (flags.dot && flags.prec > len)
	{
		zeros = flags.prec - len;
		len = flags.prec;
	}
	if (flags.dot && !flags.prec && n == 0)
		len = 0;
	if (n < 0 || (n >= 0 && (flags.sign || flags.space)))
		len ++;
	if (len >= flags.mfw)
	{
		print_int_signed(n, flags, zeros);
		return (len);
	}
	print_int_padded(n, flags, flags.mfw - len, zeros);
	return (flags.mfw);
}
