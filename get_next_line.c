/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:06:02 by lmedrano          #+#    #+#             */
/*   Updated: 2022/12/05 16:51:39 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// create a cursor var
// create a buf var
// create a static var that stores what is currently read
// create a string var that returns a line cleaned
// make the cursor equal to buf size (to read correct amount of bytes each time)
// tant que mon fichier n'est pas fini && que je n'ai pas trouvé de '\n'
// je dis à mon cursor de lire mon fichier
// je rajoute ce que j'ai lu à ce qu'il y avait déjà dans ma static
// je sors de ma boucle et je mets à jour la ligne que je dois retourner en
// enlevant tout ce qu'il y a APRES le '\n'
// je mets à jour ma static en enlevant tout ce qu'il y a AVANT le '\n'
// je retourne ma line cleaned
// faire la gestion d'erreur : si pas de line ou pas de storage ou buffer <= 0
// ou cursor = 0 (end of file)

char *get_next_line(int fd)
{
	int		cursor;
	char		buf[BUFFER_SIZE + 1];
	static char	*storage;
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
		storage = ft_strjoin(storage, buf);
	}
	if (storage == NULL)
		return (NULL);	
	line = ft_after_backslash(storage);
	storage = ft_before_backslash(storage);
	return (line);
}
