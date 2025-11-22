/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaialons <jaialons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:13:58 by jaialons          #+#    #+#             */
/*   Updated: 2025/10/15 19:05:40 by jaialons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_char(va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	return (ft_putchar(c));
}

int	format_str(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	return (ft_putstr(str));
}

int	format_ptr(va_list args)
{
	void	*ptr;

	ptr = va_arg(args, void *);
	return (ft_putptr(ptr));
}

int	process(va_list args, char format)
{
	if (format == 'c')
		return (format_char(args));
	else if (format == 's')
		return (format_str(args));
	else if (format == 'p')
		return (format_ptr(args));
	else if (format == 'd' || format == 'i')
		return (format_nbr(args));
	else if (format == 'u')
		return (format_unbr(args));
	else if (format == 'x' || format == 'X')
		return (format_hex(args, format));
	else if (format == '%')
		return (ft_putchar('%'));
	return (0);
}
