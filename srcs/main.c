/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:26:35 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/03/14 11:24:19 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*void	display_map(char **map)
{
	int	n;

	n = 0;
	while (map[n])
	{
		ft_printf("%s", map[n]);
		n++;
	}
	ft_printf("\n\n");
}

static void	free_map(char **map)
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
}*/

int main(void)
{
	/*	void	*instance;
	void	*window;
	int		sizex;
	int		sizey;
	char	*title;

	sizex = 500;
	sizey = 300;
	title = "test";
	ft_printf("test");
	instance = mlx_init();
	window = mlx_new_window(instance, sizex, sizey, title);
	mlx_loop(window);	*/

	int		fd;
	//char	**map;
	char	*str;

	fd = open("maps/small.ber", O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Mauvais file descriptor.\n");
		exit(0);
	}
	str = get_next_line(fd);
	ft_printf("%s", str);
	free(str);
	str = get_next_line(fd);
	ft_printf("%s", str);
	free(str);
	str = get_next_line(fd);
	ft_printf("%s", str);
	free(str);
	str = get_next_line(fd);
	ft_printf("%s", str);
	free(str);
	str = get_next_line(fd);
	ft_printf("%s", str);
	free(str);
	str = get_next_line(fd);
	ft_printf("%s", str);
	//map = map_creator(fd);
	//display_map(map);
	//free_map(map);
}
