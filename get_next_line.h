/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:06:28 by lmedrano          #+#    #+#             */
/*   Updated: 2022/12/12 17:10:25 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_read(int fd, char *storage);
char	*ft_strchr(char *storage, int backslash);
char	*ft_strjoin(char *storage, char *buf);
int	ft_strlen(char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_extract(char *storage);
char	*ft_clean(char *storage);

#endif
