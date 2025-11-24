/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarci2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:29:46 by jagarci2          #+#    #+#             */
/*   Updated: 2025/03/07 18:41:02 by jagarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int ftstrlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return i;
}

int main(int ac, char **av)
{
	if (ac == 4)
	{
		if (ftstrlen(av[2]) == 1 && ftstrlen(av[3]) == 1)
		{	
			int i = 0;
			
			while (av[1][i] && av[2][0] && av[3][0])
			{
				if (av[1][i] == av[2][0])
					av[1][i] = av[3][0];
				write(1, &av[1][i], 1);
				i++;
			}
			write(1, "\n", 1);
		}
		else
			return write(1, "\n", 1);
	}
	else
		return write(1, "\n", 1);
}
