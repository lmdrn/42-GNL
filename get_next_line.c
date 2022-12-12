/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:06:02 by lmedrano          #+#    #+#             */
/*   Updated: 2022/12/12 17:00:44 by lmedrano         ###   ########.fr       */
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
	{
		free(storage);
		return (NULL);
	}
	line = ft_extract(storage);
	if (!line)
	{
		free(line);
		return (NULL);
	}
//	printf("I have extracted : %s", line);
//	printf("\n");
	storage = ft_clean(storage);
//	printf("storage cleaned : %s", storage);
//	printf("\n");
	return (line);
}

char	*ft_read(int fd, char *storage)
{
	int	cursor;
	char	buf[BUFFER_SIZE + 1];

	if (!storage)
		storage = ft_calloc(1, sizeof(storage));
	if (storage == NULL)
		return (NULL);
	cursor = 1;
	while (cursor != 0 && ft_strchr(storage) != '\n')
	{
		cursor = read(fd, buf, BUFFER_SIZE);
//		printf("I have read : %s", buf);
//		printf("\n");
		if (cursor == -1)
		{
			free(storage);
			return (NULL);
		}
		buf[cursor] = '\0';
		storage = ft_strjoin(storage, buf);
//		printf("I have stored : %s", storage);
//		printf("\n");
	}
	if (storage == NULL)
		return (NULL);
	return (storage);
}
