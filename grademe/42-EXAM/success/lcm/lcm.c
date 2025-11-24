/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimega2 <jaimega2@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 11:52:59 by jaimega2          #+#    #+#             */
/*   Updated: 2025/10/31 12:33:59 by jaimega2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

unsigned int    lcm(unsigned int a, unsigned int b)
{
	unsigned int i = 2;
	unsigned int max = a * b;
	if (a == 1)
		return b;
	else if (b == 1)
		return a;
	if (a == 0 || b == 0 || a > INT_MAX || b > INT_MAX)
		return 0;
	unsigned int min = a < b ? a : b;
	while (i <= min)
	{
		if ((a % i == 0) && (b % i == 0))
			return i;
		i++;
	}
	return max;
}
/*
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	(void) ac;
	printf("%d", lcm(atoi(av[1]), atoi(av[2])));
}
*/
