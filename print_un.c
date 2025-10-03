/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_un.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 20:27:22 by mapadron          #+#    #+#             */
/*   Updated: 2025/10/03 20:27:22 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_un(unsigned int n)
{
	if (n > 9)
		return (print_un(n / 10) + print_un(n % 10));
	return (print_char('0' + n));
}
