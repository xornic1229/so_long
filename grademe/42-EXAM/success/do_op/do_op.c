/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarci2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:45:53 by jagarci2          #+#    #+#             */
/*   Updated: 2025/03/19 12:00:46 by jagarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	if (ac != 4)
		return printf("\n");

	int result = 0;
	int n1 = atoi(av[1]);
	int n2 = atoi(av[3]);
	char op = av[2][0];

	if (op == '+')
		result = n1 + n2;
	else if (op == '-')
		result = n1 - n2;
	else if (op == '*')
		result = n1 * n2;
	else if (op == '/')
		result = n1 / n2;
	else if (op == '%')
		result = n1 % n2;
	printf("%d", result);
	printf("\n");
}
