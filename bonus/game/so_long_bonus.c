/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:28:19 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/03/18 11:32:12 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

static void	put_str(t_data *data)
{
	char	*number;
	char	*str;

	number = ft_itoa(data->player.moves);
	if (!number)
		error_msg(data, "Problème d'allocation.\n");
	str = ft_strjoin("Nombre de mouvements : ", number);
	free(number);
	if (!str)
		error_msg(data, "Problème d'allocation.\n");
	mlx_put_image_to_window(data->vars.mlx, data->vars.win, data->img[6].ptr,
		5, 5);
	if (data->player.moves > 999999)
		mlx_put_image_to_window(data->vars.mlx, data->vars.win,
			data->img[6].ptr, 50, 5);
	mlx_string_put(data->vars.mlx, data->vars.win, 8, 21, 0, str);
	free(str);
}

static void	put_img(t_data *data, char c, int x, int y)
{
	int			n;
	static char	str[7] = "01PCEB";

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
	put_str(data);
}

int	so_long(int keycode, t_data *data)
{
	int				n;
	static int		array[8] = {13, 1, 0, 2, 126, 125, 123, 124};
	static t_fnct	fnct[8] = {event_up, event_down, event_left,
		event_right, event_enemy_up, event_enemy_down, event_enemy_left,
		event_enemy_right};

	n = 0;
	while (n < 8)
	{
		if (array[n] == keycode)
			break ;
		n++;
	}
	if (n < 4)
		fnct[n](data);
	else if (n < 8 && data->enemy.items == 1)
		fnct[n](data);
	else if (keycode == 53)
		end_msg(data, "Partie quittée.\n");
	return (0);
}
