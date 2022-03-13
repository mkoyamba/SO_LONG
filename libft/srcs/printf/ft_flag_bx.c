/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_bx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:49:18 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/03/13 16:55:51 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	ft_putnbr_hex(unsigned long int n, int *nb)
{
	unsigned long int	t;
	char				c;
	char				*str;

	str = "0123456789ABCDEF";
	t = n;
	if (t > 15)
		ft_putnbr_hex(t / 16, nb);
	t %= 16;
	c = str[t];
	*nb = *nb + write(1, &c, 1);
}

void	ft_flag_bx(va_list args, int *nb)
{
	unsigned long int	n;

	n = va_arg(args, unsigned int);
	ft_putnbr_hex(n, nb);
}
