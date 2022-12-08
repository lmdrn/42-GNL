/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:04:59 by lmedrano          #+#    #+#             */
/*   Updated: 2022/12/08 10:41:24 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line.c"
#include "get_next_line_utils.c"
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stddef.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

int main()
{
	int fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	char *line = NULL;
	line = get_next_line(fd);
	printf("%s\n", line);

	while (line != 0)
	{
		line = get_next_line(fd);
		printf("line res is: %s", line);
	}
}
