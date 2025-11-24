/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarci2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:36:07 by jagarci2          #+#    #+#             */
/*   Updated: 2025/03/06 15:46:22 by jagarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
	if (ac != 3)
		return (write(1, "\n", 1));

	int i = 0;
	int j;
	int count[256] = {0};
	while (av[1][i])
	{
		j = 0;
		while (av[2][j])
		{
			if (av[1][i] == av[2][j] && !count[(unsigned char)av[1][i]])
			{
				write(1, &av[1][i], 1);
				count[(unsigned char)av[1][i]] = 1;
				break ;
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
}
