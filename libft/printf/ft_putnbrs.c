/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaialons <jaialons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:13:55 by jaialons          #+#    #+#             */
/*   Updated: 2025/10/15 21:04:20 by jaialons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n)
{
	long	num;

	num = n;
	if (num < 0)
	{
		ft_putchar('-');
		num = -num;
	}
	if (num >= 10)
		ft_putnbr(num / 10);
	ft_putchar((num % 10) + '0');
}

void	ft_putunbr(unsigned int n)
{
	if (n >= 10)
		ft_putunbr(n / 10);
	ft_putchar((n % 10) + '0');
}

int	count_digits(int i)
{
	int	count;

	if (i == 0)
		return (1);
	count = 0;
	while (i != 0)
	{
		i = i / 10;
		count++;
	}
	return (count);
}

int	count_udigits(unsigned int i)
{
	int	count;

	count = 0;
	if (i == 0)
		return (1);
	while (i != 0)
	{
		i = i / 10;
		count++;
	}
	return (count);
}
