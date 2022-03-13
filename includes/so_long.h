/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:28:56 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/03/13 18:25:39 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*  		==================(     INCLUDES     )==================		  */

# include "../minilibx/mlx.h"
# include "../libft/includes/libft.h"
# include <fcntl.h>

/*  		==================(      MACROS      )==================		  */



/*  		==================(    PROTOTYPES    )==================		  */

char	**map_creator(int fd);

//test

void	display_map(char **map);

#endif