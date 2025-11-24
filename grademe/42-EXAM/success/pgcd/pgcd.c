/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarci2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:29:45 by jagarci2          #+#    #+#             */
/*   Updated: 2025/03/27 17:13:47 by jagarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	if (ac 	!= 3)
		return printf("\n");
	
	int n1 = atoi(av[1]);
	int n2 = atoi(av[2]);
	
	while (n2 != 0)
	{
		int tmp = n2;
		n2 = n1 % n2;
		n1 = tmp;
	}

	printf("%d\n", n1);
}
