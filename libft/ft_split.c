/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaialons <jaialons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 19:27:51 by jaialons          #+#    #+#             */
/*   Updated: 2025/11/20 12:03:24 by jaialons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_is_separator(char c, char sep)
{
	return (c == sep);
}

int	ft_count_words(char const *s, char sep)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && ft_is_separator(s[i], sep))
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && !ft_is_separator(s[i], sep))
				i++;
		}
	}
	return (count);
}

char	*ft_copy_word(char const *s, char sep)
{
	int	len;

	len = 0;
	while (s[len] && !ft_is_separator(s[len], sep))
		len++;
	return (ft_substr(s, 0, len));
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && ft_is_separator(s[i], c))
			i++;
		if (s[i])
		{
			res[j++] = ft_copy_word(&s[i], c);
			while (s[i] && !ft_is_separator(s[i], c))
				i++;
		}
	}
	res[j] = NULL;
	return (res);
}
