/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarci2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:57:36 by jagarci2          #+#    #+#             */
/*   Updated: 2025/03/11 13:45:47 by jagarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int check_char(char c, const char *s)
{
	int i = 0;
	
	while (s[i])
	{
		if (s[i] == c)
			return 1;
		i++;
	}
	return 0;
}


size_t	ft_strcspn(const char *s, const char *reject)
{
	int i = 0;

	while (s[i])
	{
		if (check_char(s[i], reject))
			return i;
		i++;
	}
	return i;
}
