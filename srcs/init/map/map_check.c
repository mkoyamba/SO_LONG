/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:25:24 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/03/17 21:22:29 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

void	error_check(t_data *data, int n)
{
	free_map(data->map);
	if (n == 0)
		ft_printf("Error\nLa map est trop petite.\n");
	else if (n == 1)
		ft_printf("Error\nLa map n'est pas rectangulaire.\n");
	else if (n == 2)
		ft_printf("Error\nLa map n'est pas fermée.\n");
	else if (n == 3)
		ft_printf("Error\nLa map n'a pas un contenu valide.\n");
	exit(0);
}

void	check_shape(t_data *data)
{
	int	x;

	x = 0;
	data->sizex = 0;
	data->sizey = 0;
	while (data->map[0][data->sizex] && data->map[0][data->sizex] != '\n')
		data->sizex += 1;
	while (data->map[data->sizey])
	{
		x = 0;
		while (data->map[data->sizey][x] && data->map[data->sizey][x] != '\n')
			x++;
		if (x != data->sizex)
			error_check(data, 1);
		data->sizey += 1;
	}
}

void	check_border(t_data *data)
{
	int	n;

	n = 0;
	while (n < data->sizex)
	{
		if (data->map[0][n] != '1' || data->map[data->sizey - 1][n] != '1')
			error_check(data, 2);
		n++;
	}
	n = 0;
	while (n < data->sizey)
	{
		if (data->map[n][0] != '1' || data->map[n][data->sizex - 1] != '1')
			error_check(data, 2);
		n++;
	}
}

static int	check_content_char(char i, int *c, int *e, int *p)
{
	if (i == 'C')
		*c += 1;
	else if (i == 'E')
		*e += 1;
	else if (i == 'P')
		*p += 1;
	else if (i == '0' || i == '1')
		return (1);
	else
		return (0);
	return (1);
}

void	check_content(t_data *data)
{
	int	c;
	int	e;
	int	p;
	int	x;
	int	y;

	c = 0;
	e = 0;
	p = 0;
	y = 0;
	while (y < data->sizey)
	{
		x = 0;
		while (x < data->sizex)
		{
			if (!check_content_char(data->map[y][x], &c, &e, &p))
				error_check(data, 3);
			x++;
		}
		y++;
	}
	data->player.items = c;
	if (p != 1 || e != 1 || c < 1)
		error_check(data, 3);
}
