/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:36:54 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/03/13 16:55:25 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*  		==================(     INCLUDES     )==================		  */

# include "libft.h"

/*  		==================(  MACROS/TYPEDEF  )==================		  */

typedef void	(*t_tabp)(va_list, int *);

/*  		==================(    PROTOTYPES    )==================		  */

int		ft_printf(const char *str, ...);
void	ft_flag_c(va_list args, int *nb);
void	ft_flag_d(va_list args, int *nb);
void	ft_flag_i(va_list args, int *nb);
void	ft_flag_p(va_list args, int *nb);
void	ft_flag_perc(va_list args, int *nb);
void	ft_flag_s(va_list args, int *nb);
void	ft_flag_u(va_list args, int *nb);
void	ft_flag_x(va_list args, int *nb);
void	ft_flag_bx(va_list args, int *nb);

#endif