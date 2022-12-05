/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:06:15 by lmedrano          #+#    #+#             */
/*   Updated: 2022/12/05 16:57:46 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// create ft_strlen (check sentence length)
// create ft_strjoin (join what was currently stashed in previous reading
// with current reading)
// create ft_strchr (search for a '\n' in what we've just read)
// create ft_before (remove what was before '\n' 
// and transfer it to the line to be returned)
// create ft_after (remove what was after '\n' and store it in the static var)

int	ft_strlen(char *str)
{
	int ind;

	ind = 0;
	while (str[ind] != '\0')
		ind++;
	return (ind);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int	ind;
	int	jind;
	int 	len;
	char	*new_str;

	ind = 0;
	jind = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	new_str = malloc(sizeof(char *) * (len + 1));
	if (new_str == NULL)
		return (NULL);
	while (s1)
	{
		new_str[ind] = s1[ind];
		ind++;	
	}
	while (s2)
	{
		new_str[ind] = s2[jind];
		ind++;
		jind++;
	}
	new_str[ind] = '\0';
	return (new_str);
}

char	*ft_strchr(char *str, int to_find)
{
	int	ind;
	char	letter;

	ind = 0;
	letter = to_find;

	while (str[ind] != '\0' && str[ind] != letter)
		ind++;
	if (str[ind] == letter)
		return (&str[ind]);
	return (0);
}

char	*ft_before_backslash(char *str)
{
	char	*cleaned;
	int	ind;
	int	jind;

	ind = 0;
	jind = 0;
	if (str == NULL)
		return (NULL);
	while (str[ind] != '\0' && str[ind] != '\n')
		ind++;
	cleaned = malloc(sizeof(char *) * (ft_strlen(str) - (ind + 1)));
	if (cleaned == NULL)
		return (NULL);
	ind++;
	while (str[ind] != '\0')
		cleaned[jind++] = str[ind++];
	cleaned[jind] = '\0';
	free(str);
	return (cleaned);
}

char	*ft_after_backslash(char *str)
{
	char	*cleaned;
	int 	ind;

	ind = 0;
	if (str == NULL)
		return (NULL);
	while (str[ind] != '\0' && str[ind] != '\n')
		ind++;
	cleaned = malloc(sizeof(char *) * (ind + 2));
	if (cleaned == NULL)
		return (NULL);
	if (str[ind] == '\n')
	{
		cleaned[ind] = str[ind];
		ind++;
	}
	cleaned[ind] = '\0';
	return (cleaned);
}
