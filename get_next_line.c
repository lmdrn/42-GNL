/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:06:02 by lmedrano          #+#    #+#             */
/*   Updated: 2022/11/16 16:36:16 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int	index;
	int	jindex;

	index = 0;
	jindex = 0;
	str = malloc(sizeof(char *) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (str == NULL)
		return (NULL);
	while (str[index])
	{
		str[index] = s1[index];
		index++;
	}
	while (s2[jindex])
		str[index++] = s2[jindex++];
	str[index] = '\0';
	return (str);
}

char	*ft_strchr(char *str, int to_find)
{
	char		letter;
	char		*new_str;
	int		index;

	index = 0;
	letter = to_find;
	if (str == NULL)
		return (NULL);
	new_str = (char *)str;
	while (str[index])
	{	
		if (new_str[index] == letter)
			return (&new_str[index]);
		index++;
	}
	if (new_str[index] == letter)
		return (&new_str[index]);
	return (0);
}

char	*ft_before_backslash(char *str)
{
	int	index;
	int	jindex;
	char	*line;

	index = 0;
	jindex = 0;
	while (str[index] && str[index] != '\n')
		index++;
	if (!str[index])
	{
		free(str);
		return (NULL);
	}
	line = malloc(sizeof(char) * (ft_strlen(str) - index + 1));
	if (line == NULL)
		return (NULL);
	while (str[index])
		line[jindex++] = str[index++];
	return (line);

}

char	*ft_after_backslash(char *str)
{
	int	index;
	char	*line;

	index = 0;
	if (!str[index])
		return (NULL);
	while (str[index] && str[index] != '\n')
		index++;
	line = malloc(sizeof(char *) * (index + 1));
	if (line == NULL)
		return (NULL);
	while (str[index] && str[index] != '\n')
	{
		line[index] = str[index];
		index++;
	}
	if (str[index] == '\n')
	{
		line[index] = str[index];
		index++;
	}
	line[index] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	int		cursor;
	static char	*str;
	char		*tmp;
	
	cursor = BUFFER_SIZE;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (cursor != 0)
	{
		cursor = read (fd, buf, BUFFER_SIZE);
		if (cursor == -1)
			return (NULL);
		buf[cursor] = '\0';
		tmp = str;
		str = ft_strjoin(tmp, buf);
	}
	if (str == NULL)
		return (NULL);
	tmp = str;
	tmp = ft_before_backslash(str);
	str = ft_after_backslash(str);
	return (str);
}
