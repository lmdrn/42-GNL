/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:08:08 by mreymond          #+#    #+#             */
/*   Updated: 2022/12/05 17:11:55 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.c"
#include "get_next_line_utils.c"
#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
      char *file;
      int fichier = open(file, O_RDONLY);
      file = "Hello Dolly";
//    rintf("%d", fichier);
    // printf("%s", get_next_line(1));
	char *str = NULL;

	str = get_next_line(fichier);
	printf("%s", str);
	while (str != 0)
	{
	 str = get_next_line(fichier); 
     printf("%s", str);
	}
    // get_next_line(fichier);
    // get_next_line(fichier);
    // get_next_line(fichier);
    // get_next_line(fichier);
    // get_next_line(fichier);
    // get_next_line(fichier);
    // get_next_line(fichier);
    // get_next_line(fichier);
}
