/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   null_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:12:23 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/03/17 18:23:57 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	null_init(t_data *data)
{
	size_t	n;

	n = 0;
	data->map = NULL;
	data->vars.mlx = NULL;
	data->vars.win = NULL;
	while (n < IMG_NUMBER)
	{
		data->img[n].ptr = NULL;
		n++;
	}
}
