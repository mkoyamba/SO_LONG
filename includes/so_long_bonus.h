/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:28:56 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/03/18 12:50:14 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

/*  		==================(     INCLUDES     )==================		  */

# include "../minilibx/mlx.h"
# include "../libft/includes/libft.h"
# include <fcntl.h>

/*  		==================(      MACROS      )==================		  */

# define RES 32
# define IMG_NUMBER 7

# define SOL "assets/Sol.xpm"
# define PLAYER "assets/Pichu.xpm"
# define OBJECT "assets/Pokeball.xpm"
# define WALL "assets/Wall.xpm"
# define EXIT "assets/Exit.xpm"
# define ENEMY "assets/Mewtwo.xpm"
# define MOVES "assets/Moves.xpm"

# define EV1 "assets/Pikachu.xpm"
# define EV2 "assets/Raichu.xpm"

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
	size_t		items;
	t_vars		vars;
	t_img		img[IMG_NUMBER];
	t_player	player;
	t_player	enemy;
}			t_data;

typedef void	(*t_fnct)(t_data *);

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
void	check_bonus(t_data *data);
void	error_out(char **new_map, char **map, int fd);

//	MLX

void	img_init(t_data *data);
void	mlx_start(t_data *data);

/*  		==================(   FONCTIONNEMENT   )==================		  */

void	error_msg(t_data *data, char *str);
int		end_msg(t_data *data, char *str);
void	free_map(char **map);
int		so_long(int keycode, t_data *data);
void	map_reload(t_data *data);
void	event_up(t_data *data);
void	event_down(t_data *data);
void	event_left(t_data *data);
void	event_right(t_data *data);
void	event_enemy_up(t_data *data);
void	event_enemy_down(t_data *data);
void	event_enemy_left(t_data *data);
void	event_enemy_right(t_data *data);
void	evolve(t_data *data);
int		end_msg_cross(t_data *data);

#endif