/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarci2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:42:19 by jagarci2          #+#    #+#             */
/*   Updated: 2025/03/07 19:37:16 by jagarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int n_len(char *s)
{
	int i = 0;
	while (*s)
	{
		if (*s >= 'A' && *s <= 'Z')
			i++;
		i++;
		s++;
	}
	return i;
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		char *new = malloc(n_len(av[1]) + 1);
		
		if (!new)
			return 0;

		int i = 0;
		int j = 0;

		while (av[1][i])
		{
			if (av[1][i] >= 'A' && av[1][i] <= 'Z')
			{
				if (i > 0)
				{
					new[j] = '_';
					j++;
				}
				new[j] = av[1][i] + 32;
				j++;
			}
			else
			{
				new[j] = av[1][i];
				j++;
			}
			i++;
		}
		new[j] = '\0';
		write(1, new, j);
		write(1, "\n", 1);
		free(new);
	}
	else
		write(1, "\n", 1);
}
































