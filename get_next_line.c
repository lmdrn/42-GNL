/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:06:02 by lmedrano          #+#    #+#             */
/*   Updated: 2022/12/08 11:17:36 by lmedrano         ###   ########.fr       */
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
	cursor = 1;
	while (cursor != 0 && !ft_strchr(storage, '\n'))
	{
		cursor = read(fd, buf, BUFFER_SIZE);
		if (cursor == -1)
			return (NULL);
		buf[cursor] = '\0';
		tmp = storage;
		storage = ft_strjoin(tmp, buf);
	}
	if (storage == NULL)
		return (NULL);
	line = ft_extract(storage);
	tmp = storage;
	storage = ft_clean(tmp);
	free(tmp);
	return (line);
}
