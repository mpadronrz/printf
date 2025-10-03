/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 20:27:22 by mapadron          #+#    #+#             */
/*   Updated: 2025/10/03 20:27:22 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		return (print_str("(nil)"));
	print_str("0x");
	return (2 + print_unll((unsigned long long int)ptr));
}
