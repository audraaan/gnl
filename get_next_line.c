/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarroye <alarroye@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:34:12 by alarroye          #+#    #+#             */
/*   Updated: 2024/12/11 22:38:16 by alarroye         ###   ########lyon.fr   */
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

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	res = malloc(size * nmemb);
	if (res == NULL)
		return (NULL);
	ft_memset(res, 0, size * nmemb);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	tmp[BUFFER_SIZE + 1];
	int			len;
	int			nb_read;
	char		*line;
	char		buf[BUFFER_SIZE + 1];

	if ((fd < 0) || (BUFFER_SIZE <= 0)) // si pb tu null
		return (NULL);
	line = ft_calloc(sizeof(char), 1);
	if (!line)
		return (NULL);
	ft_memset(buf, 0, BUFFER_SIZE + 1);
	len = 0;
	nb_read = 1;
	// printf("\n      <INIT>\ntmp : %s;\nline : %s;\n", tmp, line);
	if (*tmp) // si ya surplu
	{
		if (ft_n(tmp) != 0)
		{
			len = ft_n(tmp);                                 // si ya \n
			ft_memcpy(line, tmp, len);                       // fou la line
			ft_memcpy(tmp, tmp + len, ft_strlen(tmp + len)); // maj de tmp
			return (line);
		}
		else
		{
			len = ft_strlen(tmp);                            // si a pas\n
			ft_memcpy(line, tmp, len);                       // fou la line
			ft_memcpy(tmp, tmp + len, ft_strlen(tmp + len)); // maj de tmp
		}
	}
	while (1)
	{
		// printf("\n      <BOUCLE>\ntmp : %s;\nline : %s;\n", tmp, line);
		nb_read = read(fd, buf, BUFFER_SIZE);
		if (nb_read < 0) // si pb
			return (free(line), ft_memset(buf, 0, BUFFER_SIZE + 1), NULL);
		if ((nb_read == 0) && !line[0]) // si fin du file
			return (free(line), NULL);
		buf[nb_read] = '\0';
		line = ft_strjoin(line, buf);
		if (!line)
			return (NULL);
		len = ft_n(buf);
		if (len)
		{
			ft_memcpy(tmp, buf + len, ft_strlen(buf + len)); // met le reste tmp
			return (line);
		}
	}
}

int	main(void)
{
	int fd;
	int i = 0;
	fd = open("./test.txt", O_RDONLY);

	while (i < 6)
	{
		
		char *connard = get_next_line(fd);
		printf("\n      <SORTIIIIIIIIIIIIIII\n%s;", connard);
		free(connard);
		i++;
	}
	close(fd);
	return (0);
}