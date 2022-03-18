/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evolve_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 09:16:46 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/03/18 10:49:33 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

static void	picture_swap(t_data *data, int state)
{
	if (state == 0)
	{
		mlx_destroy_image(data->vars.mlx, data->img[2].ptr);
		data->img[2].ptr = mlx_xpm_file_to_image(data->vars.mlx, EV1,
				&data->img[2].sizex, &data->img[2].sizey);
		if (!data->img[2].ptr)
			error_msg(data, "Erreur lors de la compilation des images.\n");
	}
	else if (state == 1)
	{
		mlx_destroy_image(data->vars.mlx, data->img[2].ptr);
		data->img[2].ptr = mlx_xpm_file_to_image(data->vars.mlx, EV2,
				&data->img[2].sizex, &data->img[2].sizey);
		if (!data->img[2].ptr)
			error_msg(data, "Erreur lors de la compilation des images.\n");
	}
}

void	evolve(t_data *data)
{
	if (data->player.items == data->items - 1)
		picture_swap(data, 0);
	else if (data->player.items == 0)
		picture_swap(data, 1);
}
