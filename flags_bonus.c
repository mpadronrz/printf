#include "ft_printf_bonus.h"

int	is_type(char c)
{
	return (c == '%' || c == 'c' || c == 'i'
		|| c == 'd' || c == 's' || c == 'p'
		|| c == 'u' || c == 'x' || c == 'X');
}

int	ft_unsigned_atoi(char **nbr)
{
	int	n;

	n = 0;
	while ('0' <= **nbr && **nbr <= '9')
	{
		n = 10 * n + **nbr - '0';
		(*nbr)++;
	}
	(*nbr)--;
	return (n);
}

void	flag_reset(t_flags *flags)
{
	flags->mfw = 0;
	flags->sign = 0;
	flags->space = 0;
	flags->alt = 0;
	flags->zero = 0;
	flags->left = 0;
	flags->dot = 0;
	flags->prec = 0;
	flags->aux = 0;
}

void	read_flags(const char **str, t_flags *flags)
{
	(*str)++;
	while (**str && !is_type(**str))
	{
		if (**str == '+')
			flags->sign = 1;
		else if (**str == ' ')
			flags->space = 1;
		else if (**str == '#')
			flags->alt = 1;
		else if (**str == '0')
			flags->zero = 1;
		else if (**str == '-')
			flags->left = 1;
		else if (**str == '.')
		{
			flags->dot = 1;
			(*str)++;
			flags->prec = ft_unsigned_atoi((char **)str);
		}
		else if ('1' <= **str && **str <= '9')
			flags->mfw = ft_unsigned_atoi((char **)str);
		(*str)++;
	}
}
