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
	if (!line)
		return (NULL);
	storage = ft_clean(storage);
	return (line);
}

char	*ft_read(int fd, char *storage)
{
	int	cursor;
	char	buf[BUFFER_SIZE + 1];

	//if (storage == NULL)
	//	return (NULL);
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
