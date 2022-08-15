/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:51:43 by marolive          #+#    #+#             */
/*   Updated: 2022/08/15 19:43:59 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*buf_line(int fd, char *line)
{
	char	*buffer;
	int		count;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	count = 1;
	while (count && !ft_strchr(line, '\n'))
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count < 0)
			break;
		buffer[count] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	if (count < 0)
		return (NULL);
	return (line);
}

static char	*get_line(char *line)
{
	char	*malline;
	int		i;

	if (!*line)
		return (NULL);
	i = 0;
	while (line[i]  && line[i] != '\n')
		i++;
	malline = (char *)malloc(sizeof(char) * (i + 2));
	if (!malline)
		return (NULL);
	ft_strlcpy(malline, line, i + 1);
	if (line[i] == '\n')
	{
		malline[i] = '\n';
		i++;
	}
	malline[i] = '\0';
	return (malline);
}

static char	*res_line(char *line)
{
	char	*resmall;
	int		i;
	int		j;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	resmall = (char *)malloc(sizeof(char) * ((ft_strlen(line) - i) + 1));
	if (!resmall)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
		resmall[j++] = line[i++];
	resmall[j] = '\0';
	free(line);
	return (resmall);
}

char	*get_next_line(int fd)
{
	static char		*line[FD_MAX];
	char			*buff;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line[fd] = buf_line(fd, line[fd]);
	if (!line[fd])
		return (NULL);
	buff = get_line(line[fd]);
	line[fd] = res_line(line[fd]);
	return (buff);
}
