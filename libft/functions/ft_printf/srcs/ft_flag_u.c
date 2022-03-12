/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:32:48 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/03/01 11:13:05 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_putnbr(unsigned int n, int *nb)
{
	char			c;

	if (n > 9)
		ft_putnbr(n / 10, nb);
	n %= 10;
	c = n + '0';
	*nb = *nb + write(1, &c, 1);
}

void	ft_flag_u(va_list args, int *nb)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	ft_putnbr(n, nb);
}
