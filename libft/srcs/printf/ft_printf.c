/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:44:41 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/03/13 16:56:15 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_isflag(const char *str, int x)
{
	int		n;
	char	*flags;

	n = 0;
	flags = "cdip\%suxX";
	if (!str[x])
		return (0);
	while (flags[n] != str[x])
		n++;
	if (flags[n])
		return (n + 1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list			args;
	int				nb;
	static t_tabp	tab[9] = {ft_flag_c, ft_flag_d, ft_flag_i, ft_flag_p,
		ft_flag_perc, ft_flag_s, ft_flag_u, ft_flag_x, ft_flag_bx};
	int				x;

	va_start(args, str);
	nb = 0;
	x = 0;
	while (str[x])
	{
		if (str[x] == '%' && ft_isflag(str, x + 1))
		{
			tab[ft_isflag(str, x + 1) - 1](args, &nb);
			x++;
		}
		else
			nb += write(1, str + x, 1);
		x++;
	}
	va_end(args);
	return (nb);
}
