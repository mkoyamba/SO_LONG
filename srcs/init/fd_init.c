/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:54:53 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/03/30 11:52:39 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	set_player(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->sizey)
	{
		x = 0;
		while (x < data->sizex)
		{
			if (data->map[y][x] == 'P')
			{
				data->player.x = x;
				data->player.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

static int	ber_file(char *str)
{
	size_t	x;

	x = ft_strlen(str);
	if (str[x - 4] != '.' || str[x - 3] != 'b' || str[x - 2] != 'e'
		|| str[x - 1] != 'r')
		return (0);
	return (1);
}

void	fd_init(t_data *data, char **av, int ac)
{
	if (ac != 2 || ft_strlen(av[1]) < 5)
	{
		ft_printf("Error\n./so_long [map_path]\n");
		exit(0);
	}
	if (!ber_file(av[1]))
	{
		ft_printf("Error\n.La map doit être au format .ber\n");
		exit(0);
	}
	data->fd = open(av[1], O_RDONLY);
	if (data->fd < 0)
	{
		ft_printf("Error\nMauvais file descriptor.\n");
		exit(0);
	}
	data->map = map_creator(data->fd);
	map_check(data);
	set_player(data);
	close(data->fd);
}
