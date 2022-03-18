/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 09:56:32 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/03/18 10:08:52 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

static void	check_error(t_data *data, int b)
{
	if (b > 1)
		error_msg(data, "Il y a trop d'ennemis\n");
	if (b == 0)
		data->enemy.items = 0;
	else if (b == 1)
		data->enemy.items = 1;
}

void	check_bonus(t_data *data)
{
	int	b;
	int	x;
	int	y;

	b = 0;
	y = 0;
	while (y < data->sizey)
	{
		x = 0;
		while (x < data->sizex)
		{
			if (data->map[y][x] == 'B')
			{
				b++;
				data->enemy.x = x;
				data->enemy.y = y;
			}
			x++;
		}
		y++;
	}
	check_error(data, b);
}