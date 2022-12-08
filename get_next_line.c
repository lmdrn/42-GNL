/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:06:02 by lmedrano          #+#    #+#             */
/*   Updated: 2022/12/08 17:07:41 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *get_next_line(int fd)
{
	int		cursor;
	char		buf[BUFFER_SIZE + 1];
	static char	*storage;
	char		*tmp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	printf("start gnl\n");
	cursor = 1;
	storage = malloc(sizeof(char));
	if (storage == NULL)
		return (NULL);
	storage[0] = '\0';
	while (cursor != 0 && !ft_strchr(storage, '\n'))
	{
		cursor = read(fd, buf, BUFFER_SIZE);
		if (cursor == -1)
			return (NULL);
		printf("cursor value : %d\n", cursor);
		buf[cursor] = '\0';
		tmp = storage;
		printf("tmp value : %s\n", tmp);
		storage = ft_strjoin(tmp, buf);
		printf("storage value : %s\n", storage);
	}
	line = ft_extract(storage);
	printf("line value : %s\n", line);
	tmp = malloc(sizeof(*storage));
	tmp = storage;
	printf("tmp value : %s\n", tmp);
	storage = ft_clean(storage);
	printf("storage value : %s\n", storage);
	free(tmp);
	free(storage);
	printf("end gnl\n");
	return (line);
}
