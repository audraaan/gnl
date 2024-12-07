/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarroye <alarroye@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:34:12 by alarroye          #+#    #+#             */
/*   Updated: 2024/12/07 14:12:51 by alarroye         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	ls1;
	size_t	ls2;
	size_t	i;

	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	res = malloc((ls1 + ls2 + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < ls1)
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < ls2)
	{
		res[ls1] = s2[i];
		ls1++;
		i++;
	}
	res[ls1] = '\0';
	return (res);
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

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	i = 0;
	while (s[i])
		i++;
	dest = (char *)malloc(i * sizeof(char) + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1] = {0};
	int			i;
	int			y;
	int			nb_read;
	char		*res;

	i = 0;
	y = -1;
	res = ft_strdup(buf);
	while (res[i])
	{
		if (res[i] == '\n')
			while (res[i])
				res[y++] = res[i++];
		while (res[y])
		{
			ft_memset(&res[y], '\0', ft_strlen(res) - y);
			y++;
		}
		i++;
	}
	printf("\n      INIT\nbuf = %s;\nres = %s;\n", buf, res);
	while (ft_strchr(res, '\n') == NULL)
	{
		nb_read = read(fd, buf, BUFFER_SIZE);
		if (nb_read == 0)
		{
			return (NULL);
		}
		res = ft_strjoin(res, buf);
		printf("\n      BOUCLE\nbuf = %s;\nres = %s;\n", buf, res);
	}
	i = 0;
	while (res[i])
	{
		if (res[i] == '\n')
			ft_memset(&res[i + 1], '\0', ft_strlen(res) - i + 1);
		i++;
	}
	printf("\n      END\nbuf = %s;\nres = %s;\n", buf, res);
	return (res);
}

int	main(void)
{
	int fd;
	int i = 0;
	fd = open("./test.txt", O_RDONLY);
	while (i < 5)
	{
		printf("\n      SORTIIIIIIIIIIIIIII\n%s", get_next_line(fd));
		i++;
	}
	close(fd);
}