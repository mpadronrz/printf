/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 20:27:22 by mapadron          #+#    #+#             */
/*   Updated: 2025/10/03 20:27:22 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_ptrlen(unsigned long long int n)
{
	int	len;

	len = 2;
	if (n == 0)
		return (3);
	while (n != 0)
	{
		len ++;
		n /= 16;
	}
	return (len);
}

int	print_unll(unsigned long long int n)
{
	char	*base;

	base = "0123456789abcdef";
	if (n > 15)
		return (print_unll(n / 16) + print_char(base[n % 16]));
	return (print_char(base[n]));
}

int	print_ptr(void *ptr)
{
	if (!ptr)
		return (print_str("(nil)", 5));
	print_str("0x", 2);
	return (2 + print_unll((unsigned long long int)ptr));
}

void	print_ptr_padded(void *ptr, t_flags flags, int pad_len)
{
	if (!flags.left)
	{
		while (pad_len > 0)
		{
			print_char(' ');
			pad_len --;
		}
	}
	print_ptr(ptr);
	if (flags.left)
	{
		while (pad_len > 0)
		{
			print_char(' ');
			pad_len --;
		}
	}
}

int	print_ptr_flags(void *ptr, t_flags flags)
{
	int		len;

	if (!ptr)
		return (print_str_flags("(nil)", flags));
	len = ft_ptrlen((unsigned long long int)ptr);
	if (len >= flags.mfw)
	{
		print_ptr(ptr);
		return (len);
	}
	print_ptr_padded(ptr, flags, flags.mfw - len);
	return (flags.mfw);
}
