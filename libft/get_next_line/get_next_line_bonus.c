/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaialons <jaialons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:08:41 by jaialons          #+#    #+#             */
/*   Updated: 2025/11/18 17:08:42 by jaialons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_and_store(int fd, char *leftover)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!found_newline(leftover) && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(leftover);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		leftover = ft_strjoin_gnl(leftover, buffer);
	}
	free(buffer);
	return (leftover);
}

char	*extract_line(char *leftover)
{
	int		i;
	char	*line;

	if (!leftover || leftover[0] == '\0')
		return (NULL);
	i = 0;
	while (leftover[i] && leftover[i] != '\n')
		i++;
	if (leftover[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (leftover[i] && leftover[i] != '\n')
	{
		line[i] = leftover[i];
		i++;
	}
	if (leftover[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*clean_leftover(char *leftover)
{
	char	*new_leftover;
	int		i;
	int		j;

	i = 0;
	while (leftover[i] && leftover[i] != '\n')
		i++;
	if (!leftover[i])
		return (free(leftover), NULL);
	new_leftover = malloc(ft_strlen_gnl(leftover) - i);
	if (!new_leftover)
		return (NULL);
	i++;
	j = 0;
	while (leftover[i])
		new_leftover[j++] = leftover[i++];
	new_leftover[j] = '\0';
	free(leftover);
	return (new_leftover);
}

char	*get_next_line(int fd)
{
	static char	*leftover[FD_MAX];
	char		*line;

	if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	leftover[fd] = read_and_store(fd, leftover[fd]);
	if (!leftover[fd])
		return (NULL);
	line = extract_line(leftover[fd]);
	leftover[fd] = clean_leftover(leftover[fd]);
	return (line);
}
