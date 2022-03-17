/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:54:53 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/03/17 22:10:39 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

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

void	fd_init(t_data *data, char **av, int ac)
{
	if (ac != 2)
	{
		ft_printf("Error\n./so_long [map_path]\n");
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
