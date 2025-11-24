/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarci2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:15:37 by jagarci2          #+#    #+#             */
/*   Updated: 2025/03/26 14:27:39 by jagarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write (1, &c, 1);
}

int ft_atoi(char *s)
{
	int i = 0;
	int result = 0;

	while (s[i] == ' ' || s[i] == '\t')
		i++;

	while (s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	return (result);
}

void print_hex(unsigned int n)
{
	char *digits = "0123456789abcdef";

	if (n >= 16)
		print_hex(n / 16);
	ft_putchar(digits[n % 16]);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		unsigned int n = ft_atoi(av[1]);
		print_hex(n);
	}
	ft_putchar('\n');
}
