/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarci2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:01:42 by jagarci2          #+#    #+#             */
/*   Updated: 2025/03/27 16:24:44 by jagarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return i;
}

char *ft_strdup(char *src)
{
	int i = 0;
	int len = ft_strlen(src + 1);
	char *dup = malloc(len);

	if (dup == 0)
		return 0;

	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}

	dup[i] = '\0';
	return dup;
}

