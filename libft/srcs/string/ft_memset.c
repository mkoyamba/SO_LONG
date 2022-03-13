/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:31:41 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/03/01 10:34:00 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*result;
	unsigned int	n;

	n = 0;
	result = (char *)b;
	while (n < len)
	{
		result[n] = (unsigned char)c;
		n++;
	}
	return (b);
}
