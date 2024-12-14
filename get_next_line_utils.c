/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarroye <alarroye@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 09:32:26 by alarroye          #+#    #+#             */
/*   Updated: 2024/12/14 14:43:54 by alarroye         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*sr;

	sr = s;
	i = 0;
	while (i < n)
	{
		sr[i] = c;
		i++;
	}
	return (sr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*line;
	size_t	ls1;
	size_t	ls2;
	size_t	i;

	ls1 = ft_strlen(s1);
	ls2 = 0;
	while (s2[ls2] && s2[ls2] != '\n')
		ls2++;
	if (s2[ls2] == '\n')
		ls2++;
	line = malloc((ls1 + ls2 + 1) * sizeof(char));
	if (!line)
		return (free (s1), NULL);
	i = 0;
	while (i < ls1)
	{
		line[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < ls2)
		line[ls1++] = s2[i++];
	line[ls1] = '\0';
	return (free(s1), line);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	c = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strndup(const char *s, int n)
{
	char	*dest;
	int		i;

	i = 0;
	while (s[i] && i < n)
		i++;
	dest = (char *)malloc(i * sizeof(char) + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s[i] && i < n)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*s;

	s = (unsigned char *)src;
	dst = (unsigned char *)dest;
	if (dst == s)
		return (dest);
	while (n-- > 0)
		*dst++ = *s++;
	*dst++ = '\0';
	return (dest);
}
