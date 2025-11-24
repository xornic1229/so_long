/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimega2 <jaimega2@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 11:15:33 by jaimega2          #+#    #+#             */
/*   Updated: 2025/10/31 11:23:29 by jaimega2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
	if (ac != 2)
		return (write(1, "\n", 1));
	char *s = av[1];
	int i = 0;

	while(s[i])
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			if (s[i] == 'z')
				s[i] = 'a';
			else
				s[i] += 1;
		}
		else if (s[i] >= 'A' && s[i] <= 'Z')
		{
			if (s[i] == 'Z')
				s[i] = 'A';
			else
				s[i] += 1;
		}
		write(1, &s[i], 1);
		i++;
	}
	write(1, "\n", 1);
}
