/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:26:35 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/03/18 10:14:46 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_data	data;

	null_init(&data);
	fd_init(&data, argv, argc);
	data.player.moves = 0;
	data.enemy.moves = 0;
	check_bonus(&data);
	mlx_start(&data);
}
