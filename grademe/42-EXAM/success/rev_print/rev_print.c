/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarci2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:35:00 by jagarci2          #+#    #+#             */
/*   Updated: 2025/03/18 13:49:15 by jagarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ftstrlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return i;
}

int main(int ac, char **av)
{
	if (ac != 2)
		return write (1, "\n", 1);

	int i = ftstrlen(av[1]) - 1;

	while(i >= 0)
	{
		write(1, &av[1][i], 1);
		i--;
	}	
	write (1, "\n", 1);
}
