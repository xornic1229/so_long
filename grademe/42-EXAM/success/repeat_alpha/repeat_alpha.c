/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarci2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:33:43 by jagarci2          #+#    #+#             */
/*   Updated: 2025/03/04 16:55:24 by jagarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int iter(char c)
{
	char *s = "abcdefghijklmnopqrstuvwxyz";
	int i = 0;

	while (s[i] && s[i] != c)
		i++;
	return i;
}

int is_alpha(char c)
{
	if (c >= 'a' && c <= 'z')
		return 1;
	else if (c >= 'A' && c <= 'Z')
		return 2;
	return 0;
}

void print(char c, int j)
{
	if (is_alpha(c))
	{
		while(j > 0)
		{
			write(1, &c, 1);
			j--;
		}
	}
	else
		write(1, &c, 1);
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (write(1, "\n", 1));

	int i = 0;
	int j;

	while(av[1][i])
	{
		if (is_alpha(av[1][i]) == 1)
			j = (av[1][i]) - 'a' + 1;
		else if (is_alpha(av[1][i]) == 2)
			j = (av[1][i]) - 'A' + 1;

		print(av[1][i], j);
		i++;
	}
	write (1, "\n", 1);
}
