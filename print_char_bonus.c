/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 20:27:21 by mapadron          #+#    #+#             */
/*   Updated: 2025/10/03 20:27:21 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

void	print_char_padded(char c, t_flags flags, int pad_len)
{
	if (!flags.left)
	{
		while (pad_len > 0)
		{
			print_char(' ');
			pad_len --;
		}
	}
	print_char(c);
	if (flags.left)
	{
		while (pad_len > 0)
		{
			print_char(' ');
			pad_len --;
		}
	}
}

int	print_char_flags(char c, t_flags flags)
{
	if (1 >= flags.mfw)
	{
		print_char(c);
		return (1);
	}
	print_char_padded(c, flags, flags.mfw - 1);
	return (flags.mfw);
}
