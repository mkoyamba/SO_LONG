/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:28:56 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/03/14 09:52:30 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*  		==================(     INCLUDES     )==================		  */

# include "../minilibx/mlx.h"
# include "../libft/includes/libft.h"
# include <fcntl.h>

/*  		==================(      MACROS      )==================		  */

typedef struct s_data
{
	void			*content;
	struct s_list	*next;
}					t_data;

/*  		==================(    PROTOTYPES    )==================		  */

//char	**map_creator(int fd);

//test

//void	display_map(char **map);

#endif