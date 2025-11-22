/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaialons <jaialons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:38:11 by jaialons          #+#    #+#             */
/*   Updated: 2025/10/15 21:02:55 by jaialons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_nbr(va_list args)
{
	int	nbr;

	nbr = va_arg(args, int);
	ft_putnbr(nbr);
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		return (count_digits(-nbr) + 1);
	return (count_digits(nbr));
}

int	format_unbr(va_list args)
{
	unsigned int	unbr;

	unbr = va_arg(args, unsigned int);
	ft_putunbr(unbr);
	if (unbr == 0)
		return (1);
	return (count_udigits(unbr));
}

int	format_hex(va_list args, char format)
{
	if (format == 'x')
		return (ft_puthex(va_arg(args, unsigned int), "0123456789abcdef"));
	else
		return (ft_puthex(va_arg(args, unsigned int), "0123456789ABCDEF"));
}
