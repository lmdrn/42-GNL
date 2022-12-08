/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:06:28 by lmedrano          #+#    #+#             */
/*   Updated: 2022/12/07 16:28:33 by lmedrano         ###   ########.fr       */
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
char	*ft_strchr(char *str, int to_find);
char	*ft_strjoin(char *s1, char *s2);
int	ft_strlen(char *str);
char	*ft_extract(char *storage);
char	*ft_clean(char *storage);

#endif
