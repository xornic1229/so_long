/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaialons <jaialons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:02:04 by jaialons          #+#    #+#             */
/*   Updated: 2025/10/15 19:04:33 by jaialons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(const char s)
{
	write(1, &s, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	ft_puthex(unsigned long nbr, char *base)
{
	int	count;

	count = 0;
	if (nbr >= 16)
		count += ft_puthex(nbr / 16, base);
	count += ft_putchar(base[nbr % 16]);
	return (count);
}

int	ft_putptr(void *ptr)
{
	char			*base;
	unsigned long	nbr;

	base = "0123456789abcdef";
	nbr = (unsigned long)ptr;
	if (!ptr)
		return (ft_putstr("(nil)"));
	write(1, "0x", 2);
	return (ft_puthex(nbr, base) + 2);
}
