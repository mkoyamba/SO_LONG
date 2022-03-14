/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:13:56 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/03/14 09:49:05 by mkoyamba         ###   ########.fr       */
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

static void	error_out(char **new_map, char **map, int fd)
{
	if (new_map)
		free_map(new_map);
	if (map)
		free_map(map);
	close(fd);
	ft_printf("Une erreur est survenue lors de la compilation de la map.\n");
	exit(0);
}

static char	**map_add(char **map, char *str, int fd)
{
	char	**new_map;
	size_t	n;

	n = 0;
	if (!str)
		return (map);
	while (map[n])
		n++;
	new_map = malloc((n + 2) * sizeof(char *));
	if (!new_map)
		error_out(NULL, map, fd);
	n = 0;
	while (map[n])
	{
		new_map[n] = map[n];
		n++;
	}
	new_map[n] = str;
	new_map[n + 1] = NULL;
	free(map);
	return (new_map);
}

char	**map_creator(int fd)
{
	char	**map;
	size_t	n;

	map = malloc(2 * sizeof(char *));
	if (!map)
		error_out(NULL, NULL, fd);
	map[0] = get_next_line(fd);
	if (!map[0])
		error_out(map, NULL, fd);
	map[1] = NULL;
	n = 1;
	while (map[n - 1])
	{
		map = map_add(map, get_next_line(fd), fd);
		if (!map[n])
			break ;
		n++;
	}
	map[n] = NULL;
	return (map);
}