/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:13:56 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/03/17 17:41:10 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

void	error_out(char **new_map, char **map, int fd)
{
	if (new_map)
		free_map(new_map);
	if (map)
		free_map(map);
	if (fd >= 0)
		close(fd);
	ft_printf("Error\nErreur lors de la compilation de la map.\n");
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

void	map_check(t_data *data)
{
	if (!data->map || !data->map[0] || !data->map[1] || !data->map[2]
		|| !data->map[0][0] || !data->map[0][1] || !data->map[0][2])
		error_check(data, 0);
	check_shape(data);
	check_border(data);
	check_content(data);
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
