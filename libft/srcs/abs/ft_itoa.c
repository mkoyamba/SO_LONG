/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 17:08:50 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/03/01 10:31:25 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	lenitoa(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count++;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char			*result;
	int				i;
	unsigned int	t;

	result = malloc((lenitoa(n) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = lenitoa(n) - 1;
	if (n < 0)
	{
		t = -n;
		result[0] = '-';
	}
	else
		t = n;
	while (t != 0 || (i == 0 && n == 0))
	{
		result[i] = t % 10 + '0';
		t /= 10;
		i--;
	}
	result[lenitoa(n)] = '\0';
	return (result);
}
