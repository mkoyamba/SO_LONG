/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:46:15 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/03/18 11:20:04 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	img_init(t_data *data)
{
	size_t		n;
	static char	*img[IMG_NUMBER] = {SOL, WALL, PLAYER, OBJECT, EXIT, ENEMY,
		MOVES};

	n = 0;
	while (n < IMG_NUMBER)
	{
		data->img[n].ptr = mlx_xpm_file_to_image(data->vars.mlx, img[n],
				&data->img[n].sizex, &data->img[n].sizey);
		if (!data->img[n].ptr)
			error_msg(data, "Erreur lors de la compilation des images.\n");
		n++;
	}
}
