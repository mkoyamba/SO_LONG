/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:18:59 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/03/17 22:12:18 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	free_map(char **map)
{
	int	n;

	n = 0;
	while (map[n])
	{
		free(map[n]);
		n++;
	}
	if (map)
		free(map);
}

int	end_msg(t_data *data)
{
	size_t	n;

	n = 0;
	if (data->map)
		free_map(data->map);
	while (n < IMG_NUMBER)
	{
		if (data->img[n].ptr)
			mlx_destroy_image(data->vars.mlx, data->img[n].ptr);
		n++;
	}
	if (data->vars.win)
		mlx_destroy_window (data->vars.mlx, data->vars.win);
	if (data->vars.mlx)
		free(data->vars.mlx);
	ft_printf("Fin\nJ'espere que vous avez apreciez le jeu! :)\n");
	exit(0);
	return (0);
}

void	error_msg(t_data *data, char *str)
{
	size_t	n;

	if (data->map)
		free_map(data->map);
	if (data->vars.mlx)
		free(data->vars.mlx);
	if (data->vars.win)
		free(data->vars.win);
	n = 0;
	while (n < IMG_NUMBER)
	{
		if (data->img[n].ptr)
			free(data->img[n].ptr);
		n++;
	}
	if (str)
		ft_printf("Error\n%s", str);
	exit(0);
}
