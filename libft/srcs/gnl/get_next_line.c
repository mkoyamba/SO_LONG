/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 22:07:56 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/03/13 18:43:26 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

static char	*ft_strchr_gnl(char *s, int c)
{
	int	x;

	x = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[g_ft_strlen(s)]);
	while (s[x] != '\0')
	{
		if (s[x] == (char) c)
			return ((char *)&s[x]);
		x++;
	}
	return (0);
}

static char	*ft_strjoin_gnl(char *str, char *buff)
{
	size_t	a;
	size_t	b;
	char	*line;

	if (!str)
	{
		str = (char *)malloc(sizeof(char) * 1);
		if (!str || !buff)
			return (NULL);
		str[0] = '\0';
	}
	line = malloc(sizeof(char) * ((g_ft_strlen(str) + g_ft_strlen(buff)) + 1));
	if (line == NULL)
		return (NULL);
	a = -1;
	b = 0;
	if (str)
		while (str[++a] != '\0')
			line[a] = str[a];
	while (buff[b] != '\0')
		line[a++] = buff[b++];
	line[g_ft_strlen(str) + g_ft_strlen(buff)] = '\0';
	free(str);
	return (line);
}

char	*ft_read(int fd, char *str)
{
	char	*buff;
	int		rd;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	rd = 1;
	while (!ft_strchr_gnl(str, '\n') && rd != 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == 0)
			break ;
		if (rd == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd] = '\0';
		str = ft_strjoin_gnl(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (NULL);
	str[fd] = ft_read(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = ft_get_line(str[fd]);
	if (!ft_strchr_gnl(str[fd], '\n'))
	{
		if (!str[fd][0])
		{
			free(str[fd]);
			return (NULL);
		}
		free(str[fd]);
		return (line);
	}
	str[fd] = ft_update(str[fd]);
	return (line);
}
