/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:32:45 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/03/01 11:13:02 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	ft_strlen(char *str)
{
	size_t	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

void	ft_flag_s(va_list args, int *nb)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		*nb = *nb + write(1, "(null)", 6);
	else
		*nb = *nb + write(1, str, ft_strlen(str));
}
