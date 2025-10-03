/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 20:27:21 by mapadron          #+#    #+#             */
/*   Updated: 2025/10/03 20:27:21 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ar(va_list ar, char tp)
{
	int	bytes;

	bytes = 0;
	if (tp == '%')
		bytes = print_char('%');
	else if (tp == 'c')
		bytes = print_char((unsigned char)va_arg(ar, int));
	else if (tp == 's')
		bytes = print_str(va_arg(ar, char *));
	else if (tp == 'i' || tp == 'd')
		bytes = print_int(va_arg(ar, int));
	else if (tp == 'p')
		bytes = print_ptr(va_arg(ar, void *));
	else if (tp == 'u')
		bytes = print_un(va_arg(ar, unsigned int));
	else if (tp == 'x' || tp == 'X')
		bytes = print_hex(va_arg(ar, unsigned int), tp);
	return (bytes);
}

int	ft_printf(const char *str, ...)
{
	va_list	ar;
	int		bytes;

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
			str ++;
			bytes += print_ar(ar, *str);
		}
		str ++;
	}
	va_end(ar);
	return (bytes);
}
