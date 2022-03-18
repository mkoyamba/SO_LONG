/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_enemy_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 09:47:54 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/03/18 10:45:11 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	event_enemy_up(t_data *data)
{
	if (data->map[data->enemy.y - 1][data->enemy.x] == '1' ||
		data->map[data->enemy.y - 1][data->enemy.x] == 'C' ||
		data->map[data->enemy.y - 1][data->enemy.x] == 'E')
		return ;
	else if (data->map[data->enemy.y - 1][data->enemy.x] == '0')
	{
		data->map[data->enemy.y - 1][data->enemy.x] = 'B';
		data->map[data->enemy.y][data->enemy.x] = '0';
		data->enemy.moves += 1;
		data->enemy.y -= 1;
	}
	else if (data->map[data->enemy.y - 1][data->enemy.x] == 'P')
		end_msg(data);
	map_reload(data);
}

void	event_enemy_down(t_data *data)
{
	if (data->map[data->enemy.y + 1][data->enemy.x] == '1' ||
		data->map[data->enemy.y + 1][data->enemy.x] == 'C' ||
		data->map[data->enemy.y + 1][data->enemy.x] == 'E')
		return ;
	else if (data->map[data->enemy.y + 1][data->enemy.x] == '0')
	{
		data->map[data->enemy.y + 1][data->enemy.x] = 'B';
		data->map[data->enemy.y][data->enemy.x] = '0';
		data->enemy.moves += 1;
		data->enemy.y += 1;
	}
	else if (data->map[data->enemy.y + 1][data->enemy.x] == 'P')
		end_msg(data);
	map_reload(data);
}

void	event_enemy_left(t_data *data)
{
	if (data->map[data->enemy.y][data->enemy.x - 1] == '1' ||
		data->map[data->enemy.y][data->enemy.x - 1] == 'C' ||
		data->map[data->enemy.y][data->enemy.x - 1] == 'E')
		return ;
	else if (data->map[data->enemy.y][data->enemy.x - 1] == '0')
	{
		data->map[data->enemy.y][data->enemy.x - 1] = 'B';
		data->map[data->enemy.y][data->enemy.x] = '0';
		data->enemy.moves += 1;
		data->enemy.x -= 1;
	}
	else if (data->map[data->enemy.y][data->enemy.x - 1] == 'P')
		end_msg(data);
	map_reload(data);
}

void	event_enemy_right(t_data *data)
{
	if (data->map[data->enemy.y][data->enemy.x + 1] == '1' ||
		data->map[data->enemy.y][data->enemy.x + 1] == 'C' ||
		data->map[data->enemy.y][data->enemy.x + 1] == 'E')
		return ;
	else if (data->map[data->enemy.y][data->enemy.x + 1] == '0')
	{
		data->map[data->enemy.y][data->enemy.x + 1] = 'B';
		data->map[data->enemy.y][data->enemy.x] = '0';
		data->enemy.moves += 1;
		data->enemy.x += 1;
	}
	else if (data->map[data->enemy.y][data->enemy.x + 1] == 'P')
		end_msg(data);
	map_reload(data);
}
