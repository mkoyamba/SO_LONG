/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:59:50 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/03/01 10:33:25 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	mk_check_atoi(const char *str, int n, int s)
{
	int				a;
	unsigned long	l;

	a = 0;
	l = 0;
	while (str[n + a] >= '0' && str[n + a] <= '9')
		a++;
	if (a > 19 && s == 1)
		return (-1);
	if (a > 19 && s == -1)
		return (0);
	while (str[n] >= '0' && str[n] <= '9')
	{
		l *= 10;
		l += str[n] - '0';
		n++;
	}
	if (l > 9223372036854775807 && s == 1)
		return (-1);
	if (l > 9223372036854775807 && s == -1 && str[n - 1] > '8')
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	int	s;
	int	n;
	int	nombre;

	nombre = 0;
	n = 0;
	s = 1;
	while (str[n] == ' ' || str[n] == '\t' || str[n] == '\n'
		|| str[n] == '\r' || str[n] == '\v' || str[n] == '\f')
		n++;
	if (str[n] == '+' || str[n] == '-')
	{
		if (str[n] == '-')
			s = -s;
		n++;
	}
	if (mk_check_atoi(str, n, s) == -1 || mk_check_atoi(str, n, s) == 0)
		return (mk_check_atoi(str, n, s));
	while (str[n] >= '0' && str[n] <= '9')
	{
		nombre *= 10;
		nombre += str[n] - '0';
		n++;
	}
	return (nombre * s);
}
