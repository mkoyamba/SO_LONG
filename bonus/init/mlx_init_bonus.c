/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:04:11 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/03/17 22:10:45 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	mlx_start(t_data *data)
{
	data->vars.mlx = mlx_init();
	data->vars.win = mlx_new_window(data->vars.mlx, data->sizex * RES,
			data->sizey * RES, "So_long");
	img_init(data);
	map_reload(data);
	mlx_hook(data->vars.win, 17, 0, end_msg, data);
	mlx_key_hook(data->vars.win, so_long, data);
	mlx_loop(data->vars.mlx);
}
