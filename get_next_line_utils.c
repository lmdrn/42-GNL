/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:06:15 by lmedrano          #+#    #+#             */
/*   Updated: 2022/12/12 17:04:35 by lmedrano         ###   ########.fr       */
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


int	ft_strlen(char *str)
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
	size_t	j;
	size_t	count;

	i = 0;
	j = 0;
	if (storage == NULL || buf == NULL)
		return (NULL);
	count = ft_strlen(storage) + ft_strlen(buf);
	//printf("storage length is : %d\n", ft_strlen(storage));
	//printf("buf length is : %d\n", ft_strlen(buf));
	str = ft_calloc(count, sizeof(str));
	if (str == NULL)
		return (NULL);
	while (storage[i] != '\0')
	{
		str[i] = storage[i];
		i++;
	}
	while (buf[j] != '\0')
		str[i++] = buf[j++];
	free(storage);
	str[i] = '\0';
	return (str);
}

int	ft_strchr(char *storage)
{
	int	i;

	i = 0;
	if (storage == NULL)
		return (-1);
	while (storage[i] != '\0')
	{
		if (storage[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

// create function that EXTRACTS content in storage
// before \n + \n and COPIES it into line

char	*ft_extract(char *storage)
{
	char	*extracted;
	int	i;

	i = 0;
	if (!*storage)
	{
		free(storage);
		return (NULL);
	}
	while (storage[i] != '\0' && storage[i] != '\n')
		i++;
	i++;
	extracted = ft_calloc(i, sizeof(extracted));
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
	int	i;
	int	j;

	i = 0;
	if (!*storage)
	{
		free(storage);
		return (NULL);
	}
	while (storage[i] != '\0' && storage[i] != '\n')
		i++;
	cleaned = ft_calloc((ft_strlen(storage) - i), sizeof(cleaned));
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
