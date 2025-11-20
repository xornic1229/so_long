/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaialons <jaialons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:58:36 by jaialons          #+#    #+#             */
/*   Updated: 2025/11/20 12:03:14 by jaialons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sol;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	sol = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!sol)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		sol[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		sol[i] = s2[j];
		i++;
		j++;
	}
	sol[i] = '\0';
	return (sol);
}
