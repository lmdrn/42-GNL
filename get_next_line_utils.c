/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:06:15 by lmedrano          #+#    #+#             */
/*   Updated: 2022/12/08 11:24:16 by lmedrano         ###   ########.fr       */
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

char	*ft_strjoin(char *s1, char  *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[i] = '\0';
	}
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	count = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * count + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	free(s1);
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(char *str, int to_find)
{
	int	i;
	char	letter;

	i = 0;
	letter = to_find;
	if (str == NULL)
		return (NULL);
	while (str[i] != '\0' && str[i] != letter)
		i++;
	if (str[i] == letter)
		return (&str[i]);
	return (NULL);
}

// create function that EXTRACTS content in storage
// before \n + \n and COPIES it into line


char	*ft_extract(char *storage)
{
	char	*extracted;
	int	i;

	i = 0;
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
		extracted[i] = storage[i];
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
	if (storage == NULL)
	{
		free(storage);
		return (NULL);
	}
	while (storage[i] != '\0' && storage[i] != '\n')
		i++;
	cleaned = malloc(sizeof(char) * ((ft_strlen(storage) - i) + 1));
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
