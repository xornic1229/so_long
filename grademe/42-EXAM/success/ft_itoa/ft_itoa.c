/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarci2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:51:16 by jagarci2          #+#    #+#             */
/*   Updated: 2025/03/26 14:51:45 by jagarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_nbrlen(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;
	int		sign;

	size = ft_nbrlen(n);
	sign = 1;
	if (n < 0)
		sign = -1;
	str = malloc(size + 1);
	if (!str)
		return (0);
	str[size] = '\0';
	while (size > 0)
	{
		str[size - 1] = (n % 10) * sign + '0';
		n = n / 10;
		size--;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}

