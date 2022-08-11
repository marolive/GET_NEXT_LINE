/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 20:23:56 by marolive          #+#    #+#             */
/*   Updated: 2022/08/11 08:22:01 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 80
#endif

char	*get_next_line(int fd);
//char	*buf_line(int fd, char	*line);
//char	*get_line(char *line);
//char	*res_line(char *line);

char    *ft_strchr(const char *s, int c);
size_t  ft_strlen(const char *s);
size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize);
char    *ft_strjoin(char const *s1, char const *s2);

#endif