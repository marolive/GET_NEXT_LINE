/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 21:35:25 by marolive          #+#    #+#             */
/*   Updated: 2022/08/13 07:19:51 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s && *s != (unsigned char)c)
		s++;
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t		i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dst || !src)
		return (0);
	i = 0;
	if (dstsize > 0)
	{
		while (src[i] != '\0' && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	size;

	if (!s1)
		return (0);
	size = ft_strlen(s1) + 1;
	str = (char *)malloc(size);
	if (!str)
		return (0);
	ft_strlcpy(str, s1, size);
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mall;
	size_t	count;

	if (!(s1))
		s1 = ft_strdup("");
	if (!s1 || !s2)
		return (NULL);
	count = ft_strlen(s1) + ft_strlen(s2);
	mall = malloc(count + 1);
	if (!mall)
		return (NULL);
	ft_strlcpy(mall, s1, ft_strlen(s1) + 1);
	ft_strlcpy(mall + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	free((char *)s1);
	return (mall);
}