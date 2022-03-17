/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:28:56 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/03/17 22:12:04 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

/*  		==================(     INCLUDES     )==================		  */

# include <math.h>
# include "../minilibx/mlx.h"
# include "../libft/includes/libft.h"
# include <fcntl.h>

/*  		==================(      MACROS      )==================		  */

# define RES 32
# define IMG_NUMBER 5

# define SOL "assets/Sol.xpm"
# define PLAYER "assets/Pichu.xpm"
# define OBJECT "assets/Pokeball.xpm"
# define WALL "assets/Wall.xpm"
# define EXIT "assets/Exit.xpm"

/*  		==================(     STRUCTURES     )==================		  */

typedef struct s_img
{
	void	*ptr;
	int		sizex;
	int		sizey;
}			t_img;

typedef struct s_player
{
	int		x;
	int		y;
	size_t	moves;
	size_t	items;
}			t_player;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_data
{
	int			fd;
	char		**map;
	int			sizex;
	int			sizey;
	t_vars		vars;
	t_img		img[5];
	t_player	player;
}			t_data;

/*  		==================(   INITIALISATION   )==================		  */

// DATA

void	null_init(t_data *data);

//	MAP

void	fd_init(t_data *data, char **av, int ac);
char	**map_creator(int fd);
void	map_check(t_data *data);
void	error_check(t_data *data, int n);
void	check_shape(t_data *data);
void	check_border(t_data *data);
void	check_content(t_data *data);
void	error_out(char **new_map, char **map, int fd);

//	MLX

void	img_init(t_data *data);
void	mlx_start(t_data *data);

/*  		==================(   FONCTIONNEMENT   )==================		  */

void	error_msg(t_data *data, char *str);
int		end_msg(t_data *data);
void	free_map(char **map);
int		so_long(int keycode, t_data *data);
void	map_reload(t_data *data);
void	event_up(t_data *data);
void	event_down(t_data *data);
void	event_left(t_data *data);
void	event_right(t_data *data);
void	evolve(t_data *data);

#endif