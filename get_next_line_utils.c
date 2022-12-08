/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:06:15 by lmedrano          #+#    #+#             */
/*   Updated: 2022/12/08 17:11:39 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	size_t i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *storage, char  *buf)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	j = 0;
	printf("start join\n");
	if (storage == NULL || buf == NULL)
		return (NULL);
	count = ft_strlen(storage) + ft_strlen(buf);
	printf("count value : %zu\n", count);
	str = malloc(sizeof(char) * count + 1);
	printf("str value : %s\n", str);
	if (str == NULL)
		return (NULL);
	while (storage[i] != '\0')
	{
		str[i] = storage[i];
		i++;
	}
	printf("str value after storage: %s\n", str);
	while (buf[j] != '\0')
		str[i++] = buf[j++];
	printf("str value after buf: %s\n", str);
	str[i] = '\0';
	printf("end join\n");
	return (str);
}

char	*ft_strchr(char *storage, int backslash)
{
	int	i;
	char	letter;

 	i = 0;
	letter = backslash;
	printf("start search\n");
	while (storage[i] != '\0' && storage[i] != letter)
		i++;
	if (storage[i] == letter)
		return (&storage[i]);
	printf("end search\n");
	return (NULL);
}

// create function that EXTRACTS content in storage
// before \n + \n and COPIES it into line


char	*ft_extract(char *storage)
{
	char	*extracted;
	int	i;

	i = 0;
	printf("start extract\n");
	while (storage[i] != '\0' && storage[i] != '\n')
		i++;
	extracted = malloc(sizeof(char) * i + 1);
	printf("extracted value 1 : %s\n", extracted);
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
	printf("extracted value 2: %s\n", extracted);
	extracted[i] = '\0';
	printf("end extract\n");
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
	printf("start clean\n");
	if (storage == NULL)
	{
		free(storage);
		return (NULL);
	}
	while (storage[i] != '\0' && storage[i] != '\n')
		i++;
	cleaned = malloc(sizeof(char) * ((ft_strlen(storage) - i) + 1));
	printf("cleaned value : %s\n", cleaned);
	if (cleaned == NULL)
		return (NULL);
	i++;
	j = 0;
	while (storage[i] != '\0')
		cleaned[j++] = storage[i++];
	printf("cleaned value : %s\n", cleaned);
	cleaned[j] = '\0';
	free(storage);
	printf("end clean\n");
	return (cleaned);
}
