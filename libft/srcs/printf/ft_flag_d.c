/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:32:36 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/03/13 16:55:57 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	ft_putnbr(long int n, int *nb)
{
	unsigned int	t;
	char			c;

	if (n < 0)
	{
		t = -n;
		*nb = *nb + write(1, "-", 1);
	}
	else
		t = n;
	if (t > 9)
		ft_putnbr(t / 10, nb);
	t %= 10;
	c = t + '0';
	*nb = *nb + write(1, &c, 1);
}

void	ft_flag_d(va_list args, int *nb)
{
	long int	n;

	n = va_arg(args, int);
	ft_putnbr(n, nb);
}
