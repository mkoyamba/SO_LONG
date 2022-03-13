/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:13:56 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/03/13 18:44:34 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	free_map(char **map)
{
	int	n;

	n = 0;
	while (map[n])
	{
		free(map[n]);
		n++;
	}
	if (map)
		free(map);
}

static void	error_out(char **new_map, char **map, char *str)
{
	if (new_map)
		free_map(new_map);
	if (map)
		free_map(map);
	if (str)
		free(str);
	ft_printf("Une erreur est survenue lors de la compilation de la map.\n");
	exit(0);
}

static char	**map_copy_add(char **new_map, char **map, char *str)
{
	size_t	n;

	n = 0;
	while (map[n])
	{
		new_map[n] = map[n];
		if (!new_map[n])
			error_out(new_map, map, str);
		n++;
	}
	new_map[n] = str;
	if (!new_map[n])
		error_out(new_map, map, str);
	new_map[n + 1] = NULL;
	return (new_map);
}

static char	**map_join(char **map, char *str)
{
	char	**new_map;
	size_t	n;

	n = 0;
	if (!map)
	{
		new_map = malloc(2 * sizeof(char *));
		if (!new_map)
			error_out(NULL, map, str);
		new_map[0] = str;
		if (!new_map[0])
			error_out(new_map, map, str);
		new_map[1] = NULL;
		return (new_map);
	}
	while (map[n])
		n++;
	new_map = malloc((n + 2) * sizeof(char *));
	if (!new_map)
		error_out(NULL, map, str);
	new_map = map_copy_add(new_map, map, str);
	if (!new_map)
		error_out(NULL, map, str);
	free(map);
	return (new_map);
}

char	**map_creator(int fd)
{
	char	*line;
	char	**map;

	map = NULL;
	line = get_next_line(fd);
	map = map_join(map, line);
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map = map_join(map, line);
	}
	return (map);
}