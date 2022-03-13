/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:26:35 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/03/13 13:02:39 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
	void	*instance;
	void	*window;
	int		sizex;
	int		sizey;
	char	*title;

	sizex = 500;
	sizey = 400;
	title = "test";
	instance = mlx_init();
	window = mlx_new_window(instance, sizex, sizey, title);
}