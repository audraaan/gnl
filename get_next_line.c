/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarroye <alarroye@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:34:12 by alarroye          #+#    #+#             */
/*   Updated: 2024/12/14 10:54:32 by alarroye         ###   ########lyon.fr   */
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

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	res = malloc(size * nmemb);
	if (res == NULL)
		return (NULL);
	ft_memset(res, 0, size * nmemb);
	return (res);
}

int	ft_n(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	else
		i = 0;
	return (i);
}

char	*get_next_line(int fd)
{
	static char	sspil[BUFFER_SIZE + 1];
	char		*line;
	int			len;

	line = ft_calloc(sizeof(char), 1);
	if ((fd < 0) || (BUFFER_SIZE <= 0) || !line)
		return (free(line), NULL);
	if (ft_n(sspil) != 0)
	{
		len = ft_n(sspil);
		line = ft_strjoin(line, sspil);
		if (!line)
			return (NULL);
		ft_memcpy(sspil, sspil + len, ft_strlen(sspil + len));
		return (line);
	}
	else if (*sspil)
	{
		len = ft_strlen(sspil);
		line = ft_strjoin(line, sspil);
		if (!line)
			return (NULL);
		ft_memcpy(sspil, sspil + len, ft_strlen(sspil + len));
	}
	return (ft_read(fd, sspil, line));
}

char	*ft_read(int fd, char *sspil, char *line)
{
	static char	buf[BUFFER_SIZE + 1];
	int			nb_read;
	int			len;

	ft_memset(buf, 0, BUFFER_SIZE + 1);
	while (1)
	{
		nb_read = read(fd, buf, BUFFER_SIZE);
		if (nb_read < 0)
			return (free(line), ft_memset(buf, 0, BUFFER_SIZE + 1), NULL);
		if ((nb_read == 0) && !line[0])
			return (free(line), ft_memset(buf, 0, BUFFER_SIZE + 1), NULL);
		buf[nb_read] = '\0';
		line = ft_strjoin(line, buf);
		if (!line)
			return (NULL);
		len = ft_n(buf);
		if (len)
		{
			ft_memcpy(sspil, buf + len, ft_strlen(buf + len));
			return (line);
		}
		if (nb_read == 0 && line[0])
			return (line);
	}
}

// int	main(void)
// {
// 	int		fd;
// 	int		i;
// 	char	*connard;

// 	i = 0;
// 	fd = open("./test.txt", O_RDONLY);
// 	while (i < 6)
// 	{
// 		connard = get_next_line(fd);
// 		printf("%s;\n", connard);
// 		free(connard);
// 		i++;
// 	}
// 	close(fd);
// 	return (0);
// }

//    V a foutre apres memset
// printf("\n      <INIT>\ntmp : %s;\nline : %s;\n", sspil, line);
//      V a foutre apres while(1)
// printf("\n      <BOUCLE>\ntmp : %s;\nline : %s;\n", sspil, line);