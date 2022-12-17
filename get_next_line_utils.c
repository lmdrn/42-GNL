/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:06:15 by lmedrano          #+#    #+#             */
/*   Updated: 2022/12/15 10:18:13 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*memory;
	size_t	i;
	size_t	len;

	i = 0;
	len = count * size;
	memory = malloc(len);
	if (!memory)
		return (NULL);
	while (i < len)
	{
		memory[i] = 0;
		i++;
	}
	return (memory);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *storage, char *buf)
{
	char	*str;
	size_t	i;
	size_t	count;

	i = 0;
	if (!storage)
	{
		storage = malloc(sizeof(char) * 1);
		storage[0] = '\0';
	}
	count = ft_strlen(storage) + ft_strlen(buf);
	str = malloc(sizeof(char) * count + 1);
	if (str == NULL)
		return (NULL);
	while (storage[i] != '\0')
	{
		str[i] = storage[i];
		i++;
	}
	count = 0;
	while (buf[count] != '\0')
		str[i++] = buf[count++];
	free(storage);
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(char *storage, int backslash)
{
	int	i;

	i = 0;
	if (storage == NULL)
		return (NULL);
	while ((storage[i] != '\0') && (storage[i] != (char)backslash))
		i++;
	if (storage[i] == (char)backslash)
		return (&((char *)storage)[i]);
	return (0);
}
