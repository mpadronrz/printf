/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_un_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 20:27:22 by mapadron          #+#    #+#             */
/*   Updated: 2025/10/03 20:27:22 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_unlen(unsigned int n)
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

int	print_un(unsigned int n)
{
	if (n > 9)
		return (print_un(n / 10) + print_un(n % 10));
	return (print_char('0' + n));
}

void	print_un_padded(unsigned int n, t_flags flags, int pad_len, int zeros)
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
	while (zeros-- > 0)
		print_char('0');
	if (!(flags.dot && !flags.prec && n == 0))
		print_un(n);
	if (flags.left)
	{
		while (pad_len > 0)
		{
			print_char(' ');
			pad_len --;
		}
	}
}

int	print_un_flags(unsigned int n, t_flags flags)
{
	int	len;
	int	zeros;

	len = ft_unlen(n);
	zeros = 0;
	if (flags.dot && flags.prec > len)
	{
		zeros = flags.prec - len;
		len = flags.prec;
	}
	if (flags.dot && !flags.prec && n == 0)
		len = 0;
	if (len >= flags.mfw)
	{
		print_un_padded(n, flags, 0, zeros);
		return (len);
	}
	print_un_padded(n, flags, flags.mfw - len, zeros);
	return (flags.mfw);
}
