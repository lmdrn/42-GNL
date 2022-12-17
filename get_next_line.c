/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:06:02 by lmedrano          #+#    #+#             */
/*   Updated: 2022/12/15 10:49:18 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = ft_read(fd, storage);
	if (storage == NULL)
		return (NULL);
	line = ft_extract(storage);
	storage = ft_clean(storage);
	return (line);
}

char	*ft_read(int fd, char *storage)
{
	int		cursor;
	char	buf[BUFFER_SIZE + 1];

	cursor = 1;
	while (cursor != 0)
	{
		cursor = read(fd, buf, BUFFER_SIZE);
		if (cursor == 0)
			break ;
		else if (cursor == -1)
		{
			free(storage);
			return (NULL);
		}
		buf[cursor] = '\0';
		storage = ft_strjoin(storage, buf);
		if (ft_strchr(storage, '\n'))
			break ;
	}
	return (storage);
}

// create function that EXTRACTS content in storage
// before \n + \n and COPIES it into line

char	*ft_extract(char *storage)
{
	char	*extracted;
	int		i;

	i = 0;
	if (!storage[i])
		return (NULL);
	while (storage[i] != '\0' && storage[i] != '\n')
		i++;
	i++;
	extracted = malloc(sizeof(char) * i + 1);
	if (extracted == NULL)
		return (NULL);
	i = 0;
	while (storage[i] != '\0' && storage[i] != '\n')
	{
		extracted[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
	{	
		extracted[i] = storage[i];
		i++;
	}
	extracted[i] = '\0';
	return (extracted);
}

//create function that REMOVES content in storage
//before \n + \n

char	*ft_clean(char *storage)
{
	char	*cleaned;
	int		i;
	int		j;

	i = 0;
	while (storage[i] != '\0' && storage[i] != '\n')
		i++;
	if (!storage[i])
		return (ft_free_storage(storage));
	cleaned = malloc(sizeof(char) * ft_strlen(storage) - i + 1);
	if (cleaned == NULL)
		return (NULL);
	i++;
	j = 0;
	while (storage[i] != '\0')
		cleaned[j++] = storage[i++];
	cleaned[j] = '\0';
	free(storage);
	return (cleaned);
}

char	*ft_free_storage(char *storage)
{
	free(storage);
	return (NULL);
}
