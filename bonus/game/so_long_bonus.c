/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:28:19 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/03/17 22:10:28 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

static void	put_img(t_data *data, char c, int x, int y)
{
	int			n;
	static char	str[6] = "01PCE";

	n = 0;
	while (str[n])
	{
		if (str[n] == c)
			break ;
		n++;
	}
	mlx_put_image_to_window(data->vars.mlx, data->vars.win, data->img[n].ptr,
		x * RES, y * RES);
}

void	map_reload(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->sizey)
	{
		x = 0;
		while (x < data->sizex)
		{
			put_img(data, data->map[y][x], x, y);
			x++;
		}
		y++;
	}
}

int	so_long(int keycode, t_data *data)
{
	if (keycode == 53)
		end_msg(data);
	else if (keycode == 13)
		event_up(data);
	else if (keycode == 1)
		event_down(data);
	else if (keycode == 0)
		event_left(data);
	else if (keycode == 2)
		event_right(data);
	return (0);
}
