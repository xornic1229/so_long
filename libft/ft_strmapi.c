/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaialons <jaialons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:37:51 by jaialons          #+#    #+#             */
/*   Updated: 2025/11/20 12:03:00 by jaialons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*sol;
	unsigned int	i;
	size_t			len;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	sol = malloc(sizeof(char) * (len + 1));
	if (!sol)
		return (NULL);
	i = 0;
	while (s[i])
	{
		sol[i] = f(i, s[i]);
		i++;
	}
	sol[i] = '\0';
	return (sol);
}
